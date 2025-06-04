const std = @import("std");

pub fn main() !void {
    const a = [_]u8{ 3, 4, 2, 1, 3, 3 };
    const b = [_]u8{ 4, 3, 5, 3, 9, 3 };
    const distance = try compareLists(a[0..], b[0..]);
    std.debug.print("dist: {}", .{distance});
}

/// Returns the distance of two slices
fn compareLists(a: []const u8, b: []const u8) std.mem.Allocator.Error!u8 {
    const a_sorted = try bsort(a);
    _ = b;
    //const b_sorted = bsort(b);

    std.debug.print("a: {u}\n", .{a_sorted});
    // std.debug.print("b: {u}", .{b_sorted});
    return 5;
}

fn bsort(slc: []const u8) std.mem.Allocator.Error![]u8 {
    const S = struct {
        fn orderU8(_: void, lhs: u8, rhs: u8) bool {
            return std.math.order(lhs, rhs) == .lt;
        }
    };

    std.mem.sort(u8, slc, {}, S.orderU8);

    return slc;
}
