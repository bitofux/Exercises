const std = @import("std");

pub fn main() void {
    //A bool can only be true or false
    const t: bool = true;
    const f: bool = false;
    std.debug.print("t: {}, f: {}\n", .{ t, f });

    // you can convert a bool to an integer (0 or 1 only)
    std.debug.print("t: {}, f: {}\n", .{ @intFromBool(t), @intFromBool(f) });

    //only optionals can be null
    var maybe_byte: ?u8 = null;
    std.debug.print("maybe_byte: {any}\n", .{maybe_byte});
    maybe_byte = 23;
    std.debug.print("maybe_byte: {any}\n", .{maybe_byte});
}
