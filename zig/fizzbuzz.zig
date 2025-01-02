const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    var count: u8 = 1;
    while (count <= 100) : (count += 1) {
        const div_3: u2 = @intFromBool(count % 3 == 0);
        const div_5: u1 = @intFromBool(count % 5 == 0);

        switch (div_3 << 1 | div_5) {
            2 => try stdout.writeAll("Fizz\n"),
            3 => try stdout.writeAll("Fizz Buzz\n"),
            1 => try stdout.writeAll("Buzz\n"),
            0 => try stdout.print("{}\n", .{count}),
        }
    }
}
