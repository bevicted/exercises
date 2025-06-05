const std = @import("std");
const Allocator = std.mem.Allocator;

const inputFileName = "day_1_input.txt";

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}).init;
    defer {
        if (gpa.deinit() == .leak) @panic("memory leak detected");
    }
    const malloc = gpa.allocator();
    const input = try getInput(malloc);
    defer {
        malloc.free(input.a);
        malloc.free(input.b);
    }

    const distance = try compareLists(malloc, input.a, input.b);
    std.debug.print("dist: {d}\n", .{distance});
}

/// Reads input from cwd and splits them into slices.
/// Caller owns .a && .b mem.
fn getInput(malloc: Allocator) !struct { a: []u32, b: []u32 } {
    // TODO: no idea how to get current file's dir right now
    const file = try std.fs.cwd().openFile(inputFileName, .{});
    defer file.close();
    const reader = file.reader();

    var a = std.ArrayList(u32).init(malloc);
    defer a.deinit();
    var b = std.ArrayList(u32).init(malloc);
    defer b.deinit();

    var isEven = true;
    var buf: [1024]u8 = undefined;
    while (try reader.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        var it = std.mem.splitSequence(u8, line, "   ");
        while (it.next()) |part| {
            const n = try std.fmt.parseInt(u32, part, 10);
            if (isEven) {
                try a.append(n);
                isEven = false;
                continue;
            }
            try b.append(n);
            isEven = true;
        }
    }
    return .{
        .a = try a.toOwnedSlice(),
        .b = try b.toOwnedSlice(),
    };
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
