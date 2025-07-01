const std = @import("std");


fn sum(list:[]usize) !usize{
    var total:usize = 0;
    for(list) |val|{
        total += val;
    }
    return total;
}
pub fn main() !void{
    var nums  = [_]usize{1,2,3,4,5,6,7,8,9,10};
    
    const result = sum(nums[7..10]);

    std.debug.print("Sum is: {!}\n",.{result});
}
