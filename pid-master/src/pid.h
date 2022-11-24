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

// protection against multiple includes
// 针对多个Include提供保护
#ifndef SAXBOPHONE_PID_H
#define SAXBOPHONE_PID_H

#ifdef __cplusplus
extern "C"{
#endif


    typedef struct pid_calibration {
        /*
         * struct PID_Calibration
         * 创建结构体变量  PID_校准
         * Struct storing calibrated PID constants for a PID Controller
         * 存储标定过的PID变量（对于PID控制器）的结构
         * These are used for tuning the algorithm and the values they take are
         * 这些用于调整算法，它们所取的值为
         * dependent upon the application - (in other words, YMMV...)     YMMV = you mileage may vary 
         * 取决于应用-（换句话说，YMMV…）您的里程可能会有所不同（也就是说，怎么写由你的目标来决定）
         */
        double kp; // Proportional gain //比例增益（P算法常数）
        double ki; // Integral gain     //积分增益（I算法常数）
        double kd; // Derivative gain   //微分增益（D算法常数）
    } PID_Calibration;


    typedef struct pid_state {
        /*
         * struct PID_State
         * 创建结构体变量  PID_状态
         * Struct storing the current state of a PID Controller.
         * 存储PID控制器当前状态的结构体。
         * This is used as the input value to the PID algorithm function, which also
         * returns a PID_State struct reflecting the adjustments suggested by the algorithm.
         * 这用作PID算法函数的输入值，该函数还返回一个反映算法建议的调整的PID_状态。
         * NOTE: The output field in this struct is set by the PID algorithm function, and is ignored in the actual calculations.
         * 注意：此结构中的输出字段由PID算法函数设置，在实际计算中被忽略。
         */
        double actual; // The actual reading as measured   //实际测量读数
        double target; // The desired reading              //所需读数
        double time_delta; // Time since last sample/calculation - should be set when updating state
        //自上次采样/计算以来的时间-应在更新状态时设置

        // The previously calculated error between actual and target (zero initially)
        // 之前计算的 由实际值和目标值之间的差 出来的误差（最初为零）
        double previous_error;
        double integral; // Sum of integral error over time   //随时间变化的积分误差之和（累加）
        double output;  //  the modified output value calculated by the algorithm, to compensate for error
                       // 修正后的输出值由算法计算，以补偿误差
    } PID_State;


    /*
     * PID Controller Algorithm implementation
     * PID控制器算法实现
     * Given a PID calibration for the P, I and D values and a PID_State for the current
     * 给一个pid效验 对于 P值、I值、D值 和 PID_状态 对于当前
     * state of the PID controller, calculate the new state for the PID Controller and set
     * PID控制器的状态，计算PID控制器的新状态并设置
     * the output state to compensate for any error as defined by the algorithm
     * 补偿被算法定义的任何误差的输出状态
     */
    PID_State pid_iterate(PID_Calibration calibration, PID_State state);


#ifdef __cplusplus
} // extern "C"
#endif

// end of header   //头文件尾部
#endif
