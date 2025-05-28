const std = @import("std");

pub fn main() anyerror!void {
    const num: u8 = 8;
    if (num > 8) {
        std.debug.print("a is above 10\n", .{});
    } else if (num > 10) {
        std.debug.print("a is above 8\n", .{});
    } else {
        std.debug.print("a is less than or equal to 8\n", .{});
    }

    //单行的if语句
    const if_statement: u8 = if (num > 4) num + 8 else num + 2;
    switch (num) {
        4...8 => std.debug.print("4...8\n", .{}),
        1, 10 => {
            std.debug.print("here goes more than one line of code\n", .{});
        },
        else => {},
    }
    const switch_statement = switch (num + if_statement) {
        24 => num - 2,
        10 => num + 2,
        else => if_statement + 2,
    };
    std.debug.print("switch_statement is {}\n",.{switch_statement});
}
