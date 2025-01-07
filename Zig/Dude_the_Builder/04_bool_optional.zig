const std = @import("std");
const print = std.debug.print;
pub fn main() void {
    // A bool can only be true or false
    const t: bool = true;
    const f: bool = false;
    print("t: {},f: {}\n", .{ t, f });

    // can convert a bool to integer(0 or 1)
    print("t: {d}, f: {d}\n", .{ @intFromBool(t), @intFromBool(f) });

    //optional type. only optionals can be null
    var maybe_byte: ?u8 = null;
    print("maybe_byte: {?}\n", .{maybe_byte});
    maybe_byte = 20;
    print("maybe_byte: {?}\n", .{maybe_byte});

    //if maybe_byte is null,maybe_byte.? error.
    //not null,maybe_byte.? can extract its payload
    var the_byte = maybe_byte.?; //20
    print("the_byte: {d}\n", .{the_byte});
    maybe_byte = null;
    the_byte = maybe_byte orelse 13;
    print("the_byte: {d}\n", .{the_byte});

    // you can control execution flow with if, bool and optionals.
    if (t) {
        print("it's {}\n", .{t});
    } else if (f) {
        print("it's {}\n", .{f});
    } else {
        print("None of the above are true.\n", .{});
    }
    maybe_byte = 22;
    // you can capture the payload of an optional if it's not null.
    if (maybe_byte) |tofu| {
        //In here. tofu is u8,not an optional.
        print("tofu is {}\n", .{tofu});
    } else {
        print("it's null\n", .{});
    }
    maybe_byte = null;
    // you can ignore the payload with "_"
    if (maybe_byte) |_| {
        print("it's not null\n", .{});
    } else {
        print("it's null\n", .{});
    }
    //only optional can be compared to null.
    //you can write a simple 'if' as a one liner.
    if (maybe_byte == null) print("it's null\n", .{});

    maybe_byte = 24;
    //you can use an 'if' as an expression.
    the_byte = if (maybe_byte) |b| b else 0;
    print("the_byte: {}\n", .{the_byte});
    maybe_byte = null;
    the_byte = maybe_byte orelse 0;
    print("the_byte: {}\n", .{the_byte});

    //when using 'if' as an expression,the braces are not allowed.
    the_byte = if (maybe_byte != null and maybe_byte.? == 42)
        42 * 2
    else
        0;
    print("the_byte: {}\n", .{the_byte});
}
