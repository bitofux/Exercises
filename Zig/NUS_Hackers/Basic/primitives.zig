const std = @import("std");
const print = std.debug.print;
pub fn main () !void{

    //ints
    const my_32_bit_signed_int: i32 = -42;
    const my_64_bit_signed_int:i64 = -323;
    const my_32_bit_unsigned_int: u32 = 526;
    const my_64_bit_unsigned_int: u64 = 5526;

    print("my_32_bit_signed_int: {}\n",.{my_32_bit_signed_int});
    print("my_64_bit_signed_int: {}\n",.{my_64_bit_signed_int});
    print("my_32_bit_unsigned_int: {}\n",.{my_32_bit_unsigned_int});
    print("my_64_bit_unsigned_int: {}\n",.{my_64_bit_unsigned_int});

    //more ints...
    const my_3_bit_int: i3 = -3;
    const my_5_bit_int: u5 = 30;

    print("my_3_bit_int: {}\n",.{my_3_bit_int});
    print("my_5_bit_int: {}\n",.{my_5_bit_int});

    //floats
    const my_32_bit_float: f32 = 3.14;
    const my_64_bit_float: f64 = 1.14159;
    const my_128_bit_float: f128 = 12.324543;
    print("my_32_bit_float: {}\n",.{my_32_bit_float});
    print("my_64_bit_float: {}\n",.{my_64_bit_float});
    print("my_128_bit_float: {}\n",.{my_128_bit_float});

    // bool
    const my_bool: bool = true;
    const your_bool: bool = false;
    print("my_bool: {}\n",.{my_bool});
    print("your_bool: {}\n",.{your_bool});

    // string
    const my_string:[] const u8 = "bitofux";
    print("my_string: {s}\n",.{my_string});
}
