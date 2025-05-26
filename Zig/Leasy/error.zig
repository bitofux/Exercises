const print = @import("std").debug.print;

//1.自定义一个错误集合
const number_error = error{
    NotFound,
    PermissionDenied
};

//2.定义一个返回错误联合类型的函数
fn number(num: i32) number_error!i32{
    if(num == 0) return number_error.NotFound;
    if(num < 0) return number_error.PermissionDenied;
    return num * 2;
}
pub fn main() anyerror!void{
    //3.1 使用value catch value
    const one = number(0) catch 0;
    print("one: {}\n",.{one});

    //3.2 使用value catch |err| {...}
    const two = number(-2) catch |err|{
        print("出错了,err: {}\n",.{err});
        return;
    };
    print("two: {}\n",.{two});
}
