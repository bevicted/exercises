const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}).init;
    defer {
        const check = gpa.deinit();
        if (check == .leak) @panic("memory leak detected");
    }
    const malloc = gpa.allocator();
    var a = [_]u8{ 3, 4, 2, 1, 3, 3 };
    var b = [_]u8{ 4, 3, 5, 3, 9, 3 };
    const distance = try compareLists(malloc, &a, &b);
    std.debug.print("dist: {}", .{distance});
}

/// Creates sorted copies of the two slices and returns their distance.
fn compareLists(malloc: Allocator, a: []const u8, b: []u8) Allocator.Error!u8 {
    const aSorted = try sortCopy(malloc, a);
    defer malloc.free(aSorted);
    _ = b;
    //const b_sorted = bsort(b);

    std.debug.print("a sorted: {any}\n", .{aSorted});
    // std.debug.print("b: {u}", .{b_sorted});
    return 5;
}

/// Creates sorted copy of s.
/// Caller owns the memory.
fn sortCopy(malloc: Allocator, s: []const u8) Allocator.Error![]u8 {
    const copy = try malloc.dupe(u8, s);
    std.mem.sort(u8, copy, {}, std.sort.asc(u8));
    return copy;
}
