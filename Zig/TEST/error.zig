const std = @import("std");

const tofu_error = error{
    division_is_zero,
    file_not_find,
};

fn add(var1: i32, var2: i32) !i32 {
    if (var2 == 0) {
        return tofu_error.division_is_zero; // 返回错误
    }
    return @divTrunc(var1, var2); //截断除法
}

test "error_type" {
    // 测试正常情况
    const result1 = try add(10, 2);
    try std.testing.expectEqual(result1, 5);

    // 测试错误情况
    const result2 = add(10, 0);
    try std.testing.expectError(tofu_error.division_is_zero, result2);
}
