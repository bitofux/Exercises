const std = @import("std");

pub fn main() anyerror!void {
    var num: u8 = 0;
    // while(num < 3){
    //     std.debug.print("num: {d}\n",.{num});
    //     num += 1;
    // }


    // while (num < 3) {
    //     num += 1;
    //     if (num == 2) break;
    //     std.debug.print("num: {d}\n", .{num});
    // }

    // while(num < 3){
    //     num += 1;
    //     if(num == 2) continue;
    //     std.debug.print("num: {d}\n",.{num});
    // }

    while(num < 3):(num+=1){
        if(num == 0) continue;
        std.debug.print("num: {d}\n",.{num});
    }
}
