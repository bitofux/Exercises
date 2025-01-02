const std = @import("std");

pub fn main() !void {
    //Explicit type and length
    const a1: [5]u8 = [5]u8{ 1, 2, 3, 4, 5 };
    std.debug.print("a1: {any},a1.len: {d}\n", .{ a1, a1.len });

    //Infeered type and length
    const a2 = [_]u8{ 6, 7, 8, 9, 10 };
    std.debug.print("a2: {any},a2.len: {d}\n", .{ a2, a2.len });

    var a3: [2]u8 = undefined;
    a3[0] = 1;
    a3[1] = 2;
    std.debug.print("a3[{d}]: {d},a3[{d}]: {d}\n", .{ 0, a3[0], 1, a3[1] });
}
