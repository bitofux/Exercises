const std = @import("std");

pub fn main() !void {
    const arr = [_]i32{2,3,4};
    var arr1 = [3]u32{1,2,3};
    arr1[0] = 20;
    std.debug.print("arr1[0]: {d}\n",.{arr1[0]});
    std.debug.print("hello world\n", .{});
    std.debug.print("hello,{c}orld\n",.{'w'});
    std.debug.print("hello,{s}\n",.{"world"});// character
    std.debug.print("hello,{any}\n",.{"world"});//number
    std.debug.print("hello,{any}\n",.{arr});
    std.debug.print("hello,{}\n",.{2});
    std.debug.print("hello,{}\n",.{2.3323});
}
