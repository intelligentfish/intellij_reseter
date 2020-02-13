"""

"""


def reset_intellij(records):
    """
    :return:
    """
    import os
    import win32api
    import win32con

    win32api.MessageBox(None, '按任意键开始重置试用信息', '开始重置', win32con.MB_OK)

    key = win32api.RegOpenKey(win32con.HKEY_CURRENT_USER, 'SOFTWARE\\JavaSoft\\Prefs\\jetbrains')
    if key:
        text = ''
        for (name, *_) in win32api.RegEnumKeyEx(key):
            if name in records:
                try:
                    win32api.RegDeleteTree(key, name)
                    text += '删除注册表: %s\n' % name
                    evaluation_key_path, other_xml_path = records[name]
                    os.remove(evaluation_key_path)
                    text += '删除文件: %s\n' % evaluation_key_path
                    os.remove(other_xml_path)
                    text += '删除文件: %s\n' % other_xml_path
                except Exception as ex:
                    win32api.MessageBox(None, ex, '异常信息', win32con.MB_OK | win32con.ICON_ERROR)
        win32api.RegCloseKey(key)
        win32api.MessageBox(None, text, '重置完成', win32con.MB_OK)


# 入口
if __name__ == '__main__':
    # 值修改为自己系统上对应的文件路径
    records = dict({'goland': ('C:\\Users\\Wang\\.GoLand2019.3\\config\\eval\\GoLand193.evaluation.key',
                               'C:\\Users\\Wang\\.GoLand2019.3\\config\\options\\other.xml'),
                    'clion': ('C:\\Users\\Wang\\.CLion2019.3\\config\\eval\\CLion193.evaluation.key',
                              'C:\\Users\\Wang\\.CLion2019.3\\config\\options\\other.xml'),
                    'idea': ('C:\\Users\\Wang\\.IntelliJIdea2019.3\\config\\eval\\idea193.evaluation.key',
                             'C:\\Users\\Wang\\.IntelliJIdea2019.3\\config\\options\\other.xml'),
                    'pycharm': ('C:\\Users\\Wang\\.PyCharm2019.3\\config\\eval\\PyCharm193.evaluation.key',
                                'C:\\Users\\Wang\\.PyCharm2019.3\\config\\options\\other.xml'),
                    })
    # 重置
    reset_intellij(records)
