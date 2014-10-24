#核心思想：
结构体存储字符串和逆序数，用快排排序。<p>
逆序数的计算。（分治法）
***
#注记：

1. 分治法
<p>compute;
<p>compute;
<p>merge;（分别排序，计算）
2. 二维字符串数组的初始化

		char **str;
		str = (char **)malloc(sizeof(char *) * strnum);
		for (i = 0; i < strnum; i++) {
			str[i] = (char *)malloc(sizeof(char) * (strlen + 1));
		}
3. 字符指针比大小

		int compString(const void *a, const void *b) {
			return (*((char *)a)) - (*((char *)b));
		}
4. memcpy
<p>c和c++使用的内存拷贝函数，memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。

		void *memcpy(void *dest, const void *src, size_t n);
5. 逆序数的另外两种计算方法--基本思路

		int i, j, rn = 0;
		for (i = 0; i < slen; i++) {
			for (j = i + 1; j < slen; j++) {
				if (s[i] > s[j]) {
					rn++;
				}
			}
		}
6. 逆序数的另外两种计算方法--反序遍历字符串
<p>反序遍历字符串，记录A、C、G出现的次数。

		int i, rn = 0;
		int A = 0, C = 0, G = 0;
		for (i = slen - 1; i >= 0; i--) {
			switch (s[i]) {
			case 'A':
				A++;
				break;
			case 'C':
				C++;
				rn += A;
				break;
			case 'G':
				G++;
				rn += A + C;
				break;
			case 'T':
				rn += A + C + G;
				break;
			default:
				break;
			}
		}
参考http://blog.csdn.net/lyy289065406/article/details/6647305