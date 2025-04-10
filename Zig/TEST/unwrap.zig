const std = @import("std");
const print = std.debug.print;

test "optional_value" {
    const optional_value: ?i32 = -42; //一个可选值，值为-42

    if (optional_value) |unwrap_value| {
        print("unwrap_value: {}\n", .{unwrap_value});
    } else {
        print("optional_value == null\n", .{});
    }
}

test "test_null" {
    const test_null: ?bool = null;

    if (test_null) |test_var| {
        print("test_var = {}\n", .{test_var});
    } else {
        print("test_null = null\n", .{});
    }
}

fn findvalue(index: usize) ?i32 {
    const values = [_]i32{ 20, 20, 30 };
    if (index >= values.len) return null; //如果索引超过范围，则返回null
    return values[index];
}
test "function_return_optional_value" {
    if (findvalue(2)) |result_value| {
        std.debug.print("result_value = {}\n", .{result_value});
    } else {
        print("未找到值\n", .{});
    }
}
