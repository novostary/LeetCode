# 注意事项 #
1. 问题定义
2. 对于输入合法性的判断
3. 发散性思维，无限扩展
# 旋转字符串 #


# 字符串包含 #

# 最长公共子序列 #

# 回文 #
## 回文判断 ##

## 字符串-->回文字符串 ##
http://blog.csdn.net/niushuai666/article/details/6659672

最少添加几个字符可以使给定字符串成为回文字符串
## 最长回文子串 ##
http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

http://www.felix021.com/blog/read.php?2040

Description

给定一个字符串，求它的最长回文子串的长度。

Given a string S, find the longest palindromic substring in S.

Input

Output

# 字符串转换成整数 #
## atoi ##
1. 空指针输入
2. 字符串前的空白
2. 字符串所表示数值的正负号
3. 结束条件，遇到非数字或者'\0'结束
4. 考虑溢出，分别与int值所能表示的最大(0x7fffffff)和最小值(0x8000000)进行比较

http://zhedahht.blog.163.com/blog/static/25411174200731139971/ 如何标识转换失败（Java抛出异常、C全局变量）？转换过程中使用long

JDK中parseInt的实现

http://wuchong.me/blog/2014/03/17/string-to-int/

	/*
	 * Integer 类中的 parseInt 函数
	 * Copyright (c) 1994, 2010, Oracle and/or its affiliates. All rights reserved.
	 */
	public static int parseInt (String s) throws NumberFormatException {
		return parseInt(s,10);
	}
	public static int parseInt(String s, int radix)
			throws NumberFormatException
	{
		/*
		 * WARNING: This method may be invoked early during VM initialization
		 * before IntegerCache is initialized. Care must be taken to not use
		 * the valueOf method.
		 */
		if (s == null) {
			throw new NumberFormatException( "null");//判断null的情况
		}
		if (radix < Character. MIN_RADIX) {  //转换的进制不能小于2
			throw new NumberFormatException( "radix " + radix +
											" less than Character.MIN_RADIX");
		}
		if (radix > Character. MAX_RADIX) {   //转换的进制不能大于36
			throw new NumberFormatException( "radix " + radix +
											" greater than Character.MAX_RADIX");
		}
		int result = 0;//对应整数结果
		boolean negative = false;  //保存整数的正负状态
		int i = 0, len = s.length();
		int limit = -Integer. MAX_VALUE; //合法数字的上限（下限）
		int multmin; //在做乘法计算时能走到的合法上限（下限）
		int digit; //当前字符对应的数字
		if (len > 0) {
			char firstChar = s.charAt(0);
			if (firstChar < '0') { // Possible leading "+" or "-"
				if (firstChar == '-') {
					negative = true;
					limit = Integer. MIN_VALUE;
				} else if (firstChar != '+')
					throw NumberFormatException. forInputString(s);
				if (len == 1) //不能只有一个"+"或者"-"
					throw NumberFormatException. forInputString(s);
				i++;
			}
			multmin = limit / radix;
			while (i < len) {
				// Accumulating negatively avoids surprises near MAX_VALUE
				digit = Character. digit(s.charAt(i++),radix); //以指定的进制转换整数字符
				if (digit < 0) {   //不能是非数字
					throw NumberFormatException. forInputString(s);
				}
				if (result < multmin) { //判断溢出
					throw NumberFormatException. forInputString(s);
				}
				result *= radix;
				if (result < limit + digit) {
					throw NumberFormatException. forInputString(s);
				}
				result -= digit;
			}
		} else { //字符串不能为""，即长度要大于0
			throw NumberFormatException. forInputString(s);
		}
		return negative ? result : -result;
	}


## itoa ##

## atol ##

## atof ##

http://support.microsoft.com/kb/120397/zh-cn

atof 函数需要字符串为以下形式：
   [whitespace] [sign] [digits] [\.digits] [ {d | D | e | E }[sign]digits]

http://www.docjar.com/html/api/sun/misc/FloatingDecimal.java.html

	public static double parseDouble(String s) throws NumberFormatException {
        return FloatingDecimal.readJavaFormatString(s).doubleValue();
    }

# string函数 #
## strcat ##

## strcpy ##

# others #
## memcpy ##

## memset ##

## 原码、反码、补码 ##
http://www.cnblogs.com/zhangziqiu/archive/2011/03/30/ComputerCode.html

正数的原码、反码、补码均相同。负数的补码为其反码加一。

在计算机中，负数以补码形式表达。

使用补码, 不仅仅修复了0的符号以及存在两个编码的问题, 而且还能够多表示一个最低数. 这就是为什么8位二进制, 使用原码或反码表示的范围为[-127, +127], 而使用补码表示的范围为[-128, 127]。

-1-1

减法运算法则是什么？

## Java移位符 ##
http://jinguo.iteye.com/blog/540150

移位运算符就是在二进制的基础上对数字进行平移。按照平移的方向和填充数字的规则分为三种：<<（左移）、>>（带符号右移）和>>>（无符号右移）。

>>运算规则：按二进制形式把所有的数字向右移动对应巍峨位数，低位移出（舍弃），高位的空位补符号位，即正数补零，负数补1。
## C语言内存地址基础 ##
http://www.360doc.com/content/13/0805/18/9235678_304950231.shtml

	int a = 2;
	printf("%p\n", &a);
	printf("%p\n", &a + 1);
	printf("%d\n", &a);
	0016F72C
	0016F730
	1505068


## 链表反转 ##
链表有两种，一是带头结点的：头结点存储长度信息，头结点的next指向第一个实际节点；二是不带头结点的，头结点即第一个节点。
### 从无头链表中删除节点 ###
假设有一个没有头指针的单链表，一个指针指向此单链表中间的一个节点（不是第一个，也不是最后一个节点），请将该节点从单链表中删除。

把next节点的值赋给当前节点，然后删除next。
### 判断两个链表是否相交 ###
http://www.cnblogs.com/wuyuegb2312/p/3183214.html

编程之美3.6