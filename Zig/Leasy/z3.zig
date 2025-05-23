const std = @import("std");

//1.自定义错误集合
const myerr = error{
    NotFound,
    PermissionDenied
};
//2.返回带有错误联合类型的函数
fn error_num(num: i32) myerr!i32{
    if(num == 0) return error.NotFound;
    if(num < 0 ) return error.PermissionDenied;
    return num * 2;
}

pub fn main() !void{
    //3.1 使用catch value出错时返回默认值
    const a = error_num(0) catch 0;
    std.debug.print("a = {}\n",.{a});

    //3.2 使用catch |err| {...}补捕获错误并处理
    const b = error_num(-1) catch |err|{
        std.debug.print("b 出错了，错误类型: {any}\n",.{err});
        return;
    };
    std.debug.print("b = {}\n",.{b});
}
