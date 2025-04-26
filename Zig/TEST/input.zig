const std = @import("std");

pub fn main() !void {
    var buffer: [100]u8 = undefined;
    const stdin = std.io.getStdIn().reader();
    std.debug.print("Please enter a name: \n", .{});
    const input = try stdin.readUntilDelimiter(&buffer, '\n');
    std.debug.print("You entered: {s}\n", .{input});
}
