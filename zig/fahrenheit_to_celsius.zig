const std = @import("std");

const ArgumentError = error{
    NotEnoughArguments,
};

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const args = try std.process.argsAlloc(std.heap.page_allocator);
    defer std.process.argsFree(std.heap.page_allocator, args);

    if (args.len < 2) return ArgumentError.NotEnoughArguments;

    const farenheit = try std.fmt.parseFloat(f32, args[1]);
    const celsius = (farenheit - 32) * (5.0 / 9.0);

    try stdout.print("{d:.2}c\n", .{celsius});
}
