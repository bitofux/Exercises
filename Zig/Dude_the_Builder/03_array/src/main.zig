const std = @import("std");

pub fn main() !void {

    //array literal style
    const var1_array = [_]u8{ 1, 2, 3 };
    _ = var1_array;
    //tuple literal style
    const var2_array: [3]u8 = .{ 1, 2, 3 };
    _ = var2_array;
    var var3_array: [3]u8 = undefined;
    var3_array[0] = 2;
    var3_array[1] = 3;
    var3_array[2] = 4;

    var3_array[0], var3_array[1], var3_array[2] = .{ 1, 2, 3 };

    // you can print the whole array with the {any} format specifier
    std.debug.print("{any}\n", .{var3_array});
}
