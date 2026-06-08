//!
//!  PROJECT : EXERCISES
//!  FILE    : 4.function.zig
//!  AUTHOR  : bitofux
//!  DATE    : 2026-06-06
//!  BRIEF   : 函数

const std = @import("std");

// 1. 函数内部修改变量的值
fn increment(x: *i32) void {
    x.* += 1;
}

fn test1() void {
    var x: i32 = 20;
    std.debug.print("x: {d}\n", .{x});

    increment(&x);
    std.debug.print("x: {d}\n", .{x});
}

const bitofuxEoor = error{ Overflow, InvalidCharacter, MustBePositive };
// 2. 错误处理
fn parsePositive(s: []const u8) bitofuxEoor!u32 {
    const n = try std.fmt.parseInt(u32, s, 10);

    if (n == 0) return bitofuxEoor.MustBePositive;

    return n;
}

// 3. 函数作为函数参数

fn applyTwice(f: fn (i32) i32, x: i32) i32 {
    return f(f(x));
}
fn double(x: i32) i32 {
    return x * 2;
}

pub fn main() !void {
    //1. example 1
    test1();

    //2. example 2
    // 使用try的方式调用可能抛出异常的函数，但出现异常程序会出现崩溃
    const n = try parsePositive("32");

    std.debug.print("value: {}\n", .{n});
    // 不使用try的话，可以使用catch进行捕获，并返回一个值，避免程序崩溃
    // 但是这种方法是悄无声息的捕获错误，并不知道具体到底发生了什么
    const n1 = parsePositive("aaa") catch 0;
    std.debug.print("n1: {}\n", .{n1});

    // 还有一种方法是知道具体发生了什么异常，并且给一个返回值 避免程序崩溃
    const n2 = parsePositive("aaa") catch |err| blk: {
        std.debug.print("parse failed: {s}\n", .{@errorName(err)});
        break :blk 0;
    };

    std.debug.print("n2: {}\n", .{n2});

    const n3 = applyTwice(double, 10);
    std.debug.print("n3: {d}\n", .{n3});
}
