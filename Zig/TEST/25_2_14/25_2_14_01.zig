//runtime-known
var var1: i32 = 23;

//error var1 must be comptime-known
const var2: i32 = var1;

test "test var2" {
    try @import("std").testing.expect(var2 == 33);
}
pub fn main() !void {}
