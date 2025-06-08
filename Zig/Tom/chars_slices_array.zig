const std = @import("std");
const print = std.debug.print;

pub fn main () anyerror!void{
    //printing chars,slices and arrays
    const char1_1: u8 = 'a'; //single letter

    print("single character (): {}\n", .{char1_1}); // print number
    print("single character (c): {c}\n", .{char1_1}); //print letter

    const char_array = [5]u8{'h','e','l','l','o'}; // collection of letters
    var char_slice:[] const u8 = "hello";
    char_slice = "rlds";
    // char_slice = char_array[0..3];
    var inferred_char_slice = "wangshuai";
    print("inferred_char_slice: {s}\n",.{inferred_char_slice});
    inferred_char_slice = "xiaxiaiii";
    print("char_slice: {s}\n",.{char_slice});
    print("char_array: {s}\n",.{char_array});
}
