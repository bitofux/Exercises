//!
//!  PROJECT : EXERCISES
//!  FILE    : 3.control_flow.zig
//!  AUTHOR  : bitofux
//!  DATE    : 2026-06-05
//!  BRIEF   : 控制流

const std = @import("std");

fn test1() void {
    const is_true = false;

    if (is_true) {
        std.debug.print("TRUE\n", .{});
    } else {
        std.debug.print("FALSE\n", .{});
    }
}
fn test2() void {
    const is_false = false;
    if (is_false) {
        std.debug.print("TRUE\n", .{});
    } else if (true) {
        std.debug.print("constant true\n", .{});
    } else {
        std.debug.print("FALSE\n", .{});
    }
}
fn test3() void {
    const score: u32 = 89;

    const grade = if (score >= 90) "A" else if (score >= 80 and score < 90) "B" else if (score >= 70 and score < 80) "C" else "FAIL";

    std.debug.print("score: {d} -> {s}\n", .{ score, grade });
}

fn test4() void {
    const status: u16 = 200;

    const message = switch (status) {
        200 => "Ok",
        201 => "Created",
        301, 302 => "Redirect",
        400 => "Bad Request",
        404 => "Not Found",
        500...599 => "Server Errors",
        else => "Unknown",
    };
    std.debug.print("HTTP {d}: {s}\n", .{ status, message });
}

fn getValue(is_true: bool) ?u32 {
    if (is_true) {
        return 10;
    }

    return null;
}

// 标记联合体
const Color = union(enum) { red: u8, green: u8, white: u8 };

fn test5() void {
    const color = Color{ .red = 255 };

    switch (color) {
        .red => |v| {
            std.debug.print("red: {d}\n", .{v});
        },
        .green => |v| {
            std.debug.print("green: {d}\n", .{v});
        },
        .white => |v| {
            std.debug.print("white: {d}\n", .{v});
        },
    }
}
pub fn main() void {
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    const val: u32 = getValue(true).?;
    // const val: u32 = getValue(false).?; 尝试使用null值是错误的，会终止当前进程
    std.debug.print("val: {d}\n", .{val});

    if (getValue(false)) |value| {
        std.debug.print("value: {d}\n", .{value});
    } else {
        std.debug.print("null\n", .{});
    }
}
