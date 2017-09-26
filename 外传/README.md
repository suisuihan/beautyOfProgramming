## [prettyStr.py]()

美观输出字符串，支持 dict, list, tuple类型，其他类型直接按照 str(parameter) 输出。函数需以 python 2 来运行， 如果是 python 3，需要将 isinstance(l_data, basestring) 修改为 instance(l_data, str).原因是 python 3 移除了 basestring 鸡肋，统一用 str 表示。