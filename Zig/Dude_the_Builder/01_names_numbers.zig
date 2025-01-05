const std = @import("std");

//global constant
const global_const: u8 = 26;

//global variable
var global_var: u8 = 0;

fn printInfo(name: []const u8, x: anytype) void {
    std.debug.print("{s:>10} {any:^10}\t{}\n", .{ name, x, @TypeOf(x) });
}

pub fn main() !void {
    //some output labling.
    std.debug.print("{s:>10} {s:^10}\t{s}\n", .{ "name", "value", "type" });
    std.debug.print("{s:>10} {s:^10}\t{s}\n", .{ "----", "----", "----" });

    const a_const: u16 = 1;
    printInfo("a_const", a_const);

    var a_var: u8 = 20;
    a_var += 1;
    printInfo("a_var", a_var);

    //'var'必须有一个类型或者是一个comptime
    // var b_var = 20;
    // comptime var b_var = 10;
    var b_var: i8 = 2;
    b_var += 1;
    printInfo("b_var", b_var);
}
