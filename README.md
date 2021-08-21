# 四川师范大学 软件工程 考研 C语言程序设计与数据结构:basketball_man:
此仓库包含

- C语言
- 数据结构与算法(c/c++)

## 2021 年硕士研究生招考专业目录

| 序号 | 学院及代码        | 专业及代码     | 类型   | 学制(年) | 学费(元)    | 推免生限额 | 招生计划(全日制) | 考试科目                                                     | 业务科目1参考书目 | 业务科目2参考书目                                            | 复试科目名称及参考书目                                       | 同等学力加试科目名称及参考书目                               | 跨专业加试科目名称及参考书目 | 本专业特殊要求 | 联系方式                                                     | 校区 | 备注 |
| ---- | ----------------- | -------------- | ------ | -------- | ----------- | ---------- | ---------------- | ------------------------------------------------------------ | ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------- | -------------- | ------------------------------------------------------------ | ---- | ---- |
| 49   | 013计算机科学学院 | 083500软件工程 | 学术型 | 3        | 8000(生/年) | 7          | 22               | 101思想政治理论、201英语一、302数学二、831C语言程序设计与数据结构 | 教育部指定大纲    | 1.《C语言程序设计》第4版，谭浩强著，清华大学出版社；2.《数据结构(C语言版)》，第3版，严蔚敏，吴伟民编著，清华大学出版社 | 程序设计，语言可选C与Java。《C语言程序设计》；《Java语言程序设计》，第2版，郑莉等编著，清华大学出版社 | 1.计算机网络：《计算机网络》，第5版，谢希仁，电子工业出版社；2.软件工程：《软件工程导论》，第5版，张海藩，清华大学出版设 | 不加试                       | 无             | 电话：（028）-84483992<br/>（028)-84480016  E-mail:86057765@qq.com | 成龙 |      |

## 2022 年硕士研究生招考专业目录

待更新……



## 开发环境配置

- 安装Visual Studio 2019
- 安装MinGW
- 安装WSL(可选)
- 安装并配置Clion

注：本项目是CMake工程 + 子工程，Run具体的工程前，需要Load CMake Project，然后再Reload CMake Project。

具体的安装配置过程可参考我的微信公众号文章：

- [编译、链接、库(C语言)](https://mp.weixin.qq.com/s?__biz=MzU2NzkxMzg2NQ==&mid=2247487020&idx=1&sn=a925f1f07dfc29dfdb55d1876d8f56a9&chksm=fc94b2cacbe33bdcbb2a4e28ecbb8dd4463abd2a1e5debf856e41bfd69018c30817128f7d77f&scene=178&cur_album_id=1717926328374509569#rd)
- [手撕C语言，让你不再害怕考研专业课](https://mp.weixin.qq.com/s?__biz=MzU2NzkxMzg2NQ==&mid=2247487273&idx=1&sn=2e7f6c5a5f1f38fc3020d487697efbd1&chksm=fc94b3cfcbe33ad9dfc1349180269c0bdbba39644b0206d343bddc86f2070d6b60ef88286a26&scene=178&cur_album_id=1717926328374509569#rd)

## C语言需要掌握的知识点
```js
相信程序员是C语言设计的哲学！
```
- 类型系统
- 数组
- 预处理
- 函数
- 指针
- 聚合类型
- C标准库
- POSIX扩展
- 系统底层接口
- 宏展开
- 汇编
- 链接
- 库的引入
- 依赖管理
- GUI编程

## 后续学习方向建议

- 夯实数据结构、算法基础
- 深入学习Unix/Linux系统编程
- 研发开发框架源码，如Mysql
- 学习C++、Go等更适合业务开发的语言

## 推荐相关书籍

- [C语言程序设计 现代方法 第2版 修订版](https://item.jd.com/13336014.html)
- [UNIX编程艺术]()
- [UNIX环境高级编程]()
- [程序员的自我修养]()

以上大部分书籍可在京东上买到或在京东读书APP上阅读。

## 推荐B站UP主

- [谭玉刚](https://space.bilibili.com/41036636/channel/detail?cid=161507&ctype=0)
- [编程日课DailyCoding](https://space.bilibili.com/494537125/)
- [CodingStartup起码课](https://space.bilibili.com/451368848/)
- [峰华前端工程师](https://space.bilibili.com/302954484/)
- [free-coder](https://space.bilibili.com/31273057/video)
- [代码随想录](https://space.bilibili.com/525438321/video)

## 仓库文件夹及文件说明

分为2个部分：C语言学习代码 + 数据结构与算法代码(C/C++)

- HelloWorldC：C11新标准学习C语言

1. 01.data_types.c: 数据类型
1. 02.variable.c：变量
1. 03.constant.c：常量
1. 04.operators.c：运算符
1. 05.condition.c： 条件分支语句
1. 06.loop.c：循环语句
1. 07.guess_number.c：猜数字游戏
1. 08.function_basics.c：函数基础
1. 09.function_proto_type.c：函数的原型
1. 10.variable_types_and_scope.c：变量类型和作用域
1. 11.function_varargs.c：函数的变长参数
1. 12.function_recursion.c：函数的递归
1. 13.hanoi.c：汉诺塔游戏
1. 14.custom_include_file.c：自定义头文件
1. 15.macro_function.c：宏函数
1. 16.conditional_macro.c：条件编译
1. 17.printlnf.c：宏函数实现printlnf函数
1. 18.array_basics.c：数组基础
1. 19.array_limits.c：数组的边界
1. 20.string_basics.c：字符串
1. 21.array_parameter.c：函数的数组类型的参数
1. 22.2d_array.c：二维数组
1. 23.shuffle_array.c：打乱数组的顺序
1. 24.array_quick_sort.c：数组元素的排序——快排Lomuto partition scheme
1. 25.pointer_basics.c：指针的基础
1. 26.readonly_pointer.c：只读指针变量与只读变量指针
1. 27.pointer_values.c：特殊的指针
1. 28.pointer_operations.c：指针的运算
1. 29.lvalue_rvalue.c：左值和右值
1. 30.pointer_parameter_as_return_value.c：指针的参数作为返回值
1. 31.dynamic_memory.c：动态内存分配
1. 32.function_pointer.c：函数指针与typedef
1. 33.swap_values.c：交换2个变量的值
1. 34.quick_sort.c：指针版本的快排——Hoare partition Scheme
1. 35.struct.c：结构体
1. 36.memory_align.c：结构体的内存对齐
1. 37.union.c：联合体
1. 38.enum.c：枚举
1. 39.byte_order.c: 判断字节序
1. 40.linked_list.c: 单链表的基本实现
1. 41.character_type.c：判断字符的类型
1. 42.conversion_str.c：字符串与其他数值类型的转换
1. 43.string_length_compare.c：字符串的长度与比较
1. 44.find_char_and_substring.c：查找字符与子串
1. 45.string_tokenize.c：字符串的拆分
1. 46.string_concat_copy.c：字符串的连接和复制
1. 47.mem_op.c：内存操作函数
1. 48.safe_version.c：C11的安全版本的函数
1. 49.mbs_wcs.c：宽字符串与窄字符串的转换
1. 50.time_basic.c：时间的基本概念
1. 51.get_sys_time.c：获取系统时间
1. 52.calendar.c：获取日历时间
1. 53.format_time.c 格式化时间
1. 54.parse_time.c 解析时间
1. 55.time_diff.c 计算时间差
1. 56.io_basic.c 输入输出流
1. 57.io_setbuf.c 文件流的缓冲
1. 58.read_write_a_character.c 读写一个字符
1. 59.copy_file.c 3个版本的复制文件
1. 60.read_write_a_line：读写一行字符
1. 61.read_write_certain_bytes.c: 读写指定大小的字节
1. 62.serialization.c: 序列化和反序列化的基本实现
1. 63.redirect_stdout.c: 重定向标准输入输出流
1. 64.count_character.c: 统计文件字符个数
1. 65.file_position.c: 输入输出流的位置
1. 66.file_other_operation.c: 其他的文件操作
1. 67.thread_basic.c: 线程的基础概念
1. 68.thread_safe_atomic.c: 资源的线程安全问题
1. 69.thread_safe_visiblity.c: 资源的线程安全问题
1. 70.thread_safe_visiblity.c: 资源的线程安全问题
1. 71.thread_safe_lock.c: 资源的线程安全问题
1. 72.thread_safe_local.c: 资源的线程安全问题
1. 73.thread_safe_local2.c: 资源的线程安全问题
1. 74.pure_function.c: 副作用与纯函数
1. 75.complex_thread_result.c: 处理复杂的线程返回结果
1. 76.callback.c: 函数回调
- 其它：
    - 川师考研历年真题计算机
