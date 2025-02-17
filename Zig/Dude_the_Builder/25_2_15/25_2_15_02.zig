const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    //整数类型
    //无符号整型：u8 u16 u32 u64 u128 usize(若cpu架构是64那就是u64)
    //有符号整型：i8 i16 i32 i64 i128 isize(上述同理)
    //除了这些，可以根据需要决定整型数据在内存中占了多少个bit
    //比如u1 u3 u5 u21
    //字面量表示形式可以是：decimal octal hex binary
    _ = 1_000_000; //十进制 decimal
    _ = 0x10ff_ffff; //十六进制 hex
    _ = 0o777_666; //八进制 octal
    _ = 0b10_11_10_01; //二进制 binary

    //你可以拥有任意大小
    var a_var: u1 = 1;
    a_var = 0;
    // a_var = 2;//error 2超过了这个类型所能表达的最大值

    //好处之一就是可以存储特定大小的数据可以使用精确的字节大小
    const a_const: u21 = '🦎';
    _ = a_const;

    //zig中整数类型的字面量的类型是comptime_int
    //根据初始化值进行推断b_const的类型
    const b_const = 26;
    std.debug.print("type of integer literals: {any}\n", .{@TypeOf(b_const)});
    std.debug.print("type of integer literals: {any}\n", .{@TypeOf(-1234)});

    //浮点数
    //浮点数类型：f16 f32 f64 f128
    //字面量表示形式可以是十进制(decimal)或者是十六进制(hex)
    _ = 123.0E+77; //使用指数 123 * 10^77
    _ = 123.0; //没有使用指数 123
    _ = 123.0E+77; // E or e 123 * 10^77

    _ = 0x123.70; // 1 * 16^2 + 2 * 16 + 3 * 1 + 7 / 16
    _ = 0x1.8p2; // p or P 1 * 16^0 + 8 / 16 = 1.5 1.5 * 2^2 = 6.0

    //也可以使用下划线对浮点数进行分隔以便具备可读性
    _ = 299_792_458.000_000;
    _ = 0.000_000_001;
    _ = 0x1234_5678.9ABC_CDEFp-10;

    //浮点数的无穷和NaN
    _ = std.math.inf(f64);
    _ = -std.math.inf(f64);
    _ = std.math.nan(f64);

    //浮点数的字面量类型是comptime_float
    const c_const = 0x123.7;
    std.debug.print("c_const: {any}\n", .{@TypeOf(c_const)});
}
