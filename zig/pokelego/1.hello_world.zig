//!
//!  PROJECT : EXERCISES
//!  FILE    : 1.hello_world.zig
//!  AUTHOR  : bitofux
//!  DATE    : 2026-06-02
//!  BRIEF   : zig hello world

const std = @import("std");

pub fn main() !u8 {
    std.debug.print("Hello World!\n", .{});

    return 0;
}
