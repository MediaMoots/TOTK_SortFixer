#pragma once 

#define PRINT(...)                                         \
	{                                                      \
		int len = snprintf(buf, sizeof(buf), __VA_ARGS__); \
		svcOutputDebugString(buf, len);                    \
	}        
                                              