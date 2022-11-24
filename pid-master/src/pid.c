/*
 * PID Controller Implementation in C
 * PID控制器的C语言实现
 * 
 * Created by Joshua Saxby (aka @saxbophone) on 1 Jan, 2016   aka = Also Known As
 * 由Joshua Saxby（又名saxbophone）于2016年1月1日创建
 * 
 * My own attempt at implementing the PID algorithm in some (hopefully) clean, understandable C.
 * 我自己尝试在一些（希望）干净、易懂的C语言中实现PID算法。
 *
 * See LICENSE for licensing details.
 * 有关许可证的详细信息，请参阅许可证。
 */

#include "pid.h"


PID_State pid_iterate(PID_Calibration calibration, PID_State state) {

    // calculate difference between desired and actual values (the error)
    // 计算期望值（设定值）和实际值（误差）之间的差值
    double error = state.target - state.actual;

    // calculate and update integral
    // 计算并更新赋值积分
    state.integral += (error * state.time_delta);

    // calculate derivative
    // 计算微分（导数）
    double derivative = (error - state.previous_error) / state.time_delta;

    // calculate output value according to algorithm
    // 根据算法计算输出值
    state.output = (
        (calibration.kp * error) + (calibration.ki * state.integral) + (calibration.kd * derivative)
    );

    // update state.previous_error to the error value calculated on this iteration
    // 将previous_error的值更新为error的值。也就是将这次循环误差的值赋值给previous_error
    state.previous_error = error;
    
    // return the state struct reflecting the calculations
    // 返回反映计算的状态结构
    return state;
}
