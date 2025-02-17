const std = @import("std");
const expect = std.testing.expect;

const S = struct {
    var x: i32 = 1234;
};

fn foo() i32 {
    S.x += 1;
    return S.x;
}
test "namespaced contanier level variable" {
    try expect(foo() == 1235);
    try expect(foo() == 1236);
}

pub fn main() void {}
