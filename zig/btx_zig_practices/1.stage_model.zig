//!
//!  PROJECT : EXERCISES
//!  FILE    : 1.stage_model.zig
//!  AUTHOR  : bitofux
//!  DATE    : 2026-08-09
//!  BRIEF   :
const std = @import("std");

fn twice(x: u32) u32 {
    return x * 2;
}

pub fn main() void {
    const a = comptime twice(21);

    var input: u32 = 21;
    input += 1;

    const b = twice(input);

    std.debug.print("a = {d}, b = {d}\n", .{ a, b });
}
