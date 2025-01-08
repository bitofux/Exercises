const std = @import("std");
const print = std.debug.print;
pub fn main() !void {
    // a block define a new scope
    {
        const x: u8 = 20;
        print("x: {}\n", .{x});
    }
    // cant access x.
    // print("x: {}\n", .{x});

    // blocks are expressions and can return a value
    const x: u32 = tofu: {
        const y: u8 = 23;
        const u = 23;
        print("y: {}\n", .{@TypeOf(y)});
        print("u: {}\n", .{@TypeOf(u)});
        break :tofu y + u;
    };
    print("x: {}\n", .{@TypeOf(x)});

    //'switch' controls execution flow based on value
    switch (x) {
        0...20 => print("x: {}\n", .{x}),
        21, 22, 23 => print("x: {}\n", .{x}),
        46 => {
            const u = 20;
            print("x+u: {}\n", .{x + u});
        },
        // as long as it's comptime know,any expression can be a prong
        blk: {
            const a = 20;
            const b = 30;
            break :blk a + b;
        } => print("It's 50.\n", .{}),
        else => print("none of the above!\n", .{}),
    }

    // like 'if','switch' can be a expression.
    const answer = switch (x) {
        0...10 => 1,
        46 => 2,
        else => 3,
    };
    print("answer: {d}\n", .{answer});
}
