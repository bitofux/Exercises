const std = @import("std");

pub fn main() !void {
    comptime var z = 42;
    std.debug.print("z : {}\n", .{z});
    z += 1;
}
