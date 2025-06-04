const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}).init;
    defer {
        if (gpa.deinit() == .leak) @panic("memory leak detected");
    }
    const malloc = gpa.allocator();
    var a = [_]u32{ 3, 4, 2, 1, 3, 3 };
    var b = [_]u32{ 4, 3, 5, 3, 9, 3 };
    const distance = try compareLists(malloc, &a, &b);
    std.debug.print("dist: {}", .{distance});
}

/// Creates sorted copies of the two slices and returns their distance.
fn compareLists(malloc: Allocator, a: []const u32, b: []const u32) Allocator.Error!u32 {
    const aSorted = try sortCopy(malloc, a);
    defer malloc.free(aSorted);
    const bSorted = try sortCopy(malloc, b);
    defer malloc.free(bSorted);

    var diff: u32 = 0;

    for (0..a.len) |i| {
        var bigger: u32 = undefined;
        var smaller: u32 = undefined;
        if (aSorted[i] > bSorted[i]) {
            bigger = aSorted[i];
            smaller = bSorted[i];
        } else {
            bigger = bSorted[i];
            smaller = aSorted[i];
        }
        diff += bigger - smaller;
    }

    return diff;
}

/// Creates sorted copy of s.
/// Caller owns the memory.
fn sortCopy(malloc: Allocator, s: []const u32) Allocator.Error![]u32 {
    const copy = try malloc.dupe(u32, s);
    std.mem.sort(u32, copy, {}, std.sort.asc(u32));
    return copy;
}
