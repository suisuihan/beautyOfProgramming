#!/usr/bin/env python
# -*- coding: UTF-8 -*-

def pretty_str(data, indent=2):
    def set_ret(l_data, l_width, l_indent):
        ret = ''
        if isinstance(l_data, dict):
            if len(l_data) > 1:
                l_width += l_indent
                ret = '{\n%s' % (' ' * l_width)
            else:
                for k, v in l_data.items():
                    if not isinstance(v, (dict, tuple, list)):
                        ret = '{'
                    else:
                        l_width += l_indent
                        ret = '{\n%s' % (' ' * l_width)
            for k, v in l_data.items():
                ret += '"%s": ' % k
                if isinstance(v, dict) or isinstance(v, list):
                    ret += set_ret(v, l_width, l_indent)
                elif isinstance(v, (int, float)):
                    ret += str(v)
                elif isinstance(v, basestring):
                    ret += '"%s"' % v
                else:
                    ret += str(v)
                ret += ',\n%s' % (' ' * l_width)
            ret = ret.strip().strip('\n').strip(',')
            l_width -= l_indent
            if len(l_data) > 1:
                ret += '\n%s}' % (' ' * l_width)
            else:
                for k, v in l_data.items():
                    if not isinstance(v, (dict, tuple, list)):
                        ret += '}'
                    else:
                        ret += '\n%s}' % (' ' * l_width)
        elif isinstance(l_data, list):
            if len(l_data) > 1:
                l_width += l_indent
                ret = '[\n%s' % (' ' * l_width)
            else:
                for item in l_data:
                    if not isinstance(item, (dict, tuple, list)):
                        ret = '['
                    else:
                        l_width += l_indent
                        ret = '[\n%s' % (' ' * l_width)
            for item in l_data:
                if isinstance(item, dict) or isinstance(item, list):
                    ret += set_ret(item, l_width, l_indent)
                elif isinstance(item, (int, float)):
                    ret += str(item)
                elif isinstance(item, basestring):
                    ret += '"%s"' % item
                else:
                    ret += str(item)
                ret += ',\n%s' % (' ' * l_width)
            ret = ret.strip().strip('\n').strip(',')
            l_width -= l_indent
            if len(l_data) > 1:
                ret += '\n%s]' % (' ' * l_width)
            else:
                for item in l_data:
                    if not isinstance(item, (dict, tuple, list)):
                        ret += ']'
                    else:
                        ret += '\n%s]' % (' ' * l_width)
        elif isinstance(l_data, tuple):
            if len(l_data) > 1:
                l_width += l_indent
                ret = '(\n%s' % (' ' * l_width)
            else:
                for item in l_data:
                    if not isinstance(item, (dict, tuple, list)):
                        ret = '('
                    else:
                        l_width += l_indent
                        ret = '(\n%s' % (' ' * l_width)
            for item in l_data:
                if isinstance(item, dict) or isinstance(item, list): ret += set_ret(item, l_width, l_indent)
                elif isinstance(item, (int, float)): ret += str(item)
                elif isinstance(item, basestring): ret += '"%s"' % item
                else: ret += str(item)
                ret += ',\n%s' % (' ' * l_width)
            ret = ret.strip().strip('\n').strip(',')
            l_width -= l_indent
            if len(l_data) > 1:
                ret += '\n%s)' % (' ' * l_width)
            else:
                for item in l_data:
                    if not isinstance(item, (dict, tuple, list)):
                        ret += ')'
                    else:
                        ret += '\n%s)' % (' ' * l_width)
        else:
            ret = str(l_data)
        return ret
    ret = set_ret(data, 0, indent)
    return ret

test = {'a': 'fuck', 'b': 1.0, 'c': {'d':[1,3,5]}}
print(pretty_str(test))
