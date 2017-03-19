#ifndef myCmd_h__
#define myCmd_h__

/*

@!CLIENT LIST 连接客户端列表
@!CLIENT KICK 强制断开客户端
@!CLIENT NAME 给连接客户端命名 设置为账号名称
@!CLIENT LOGIN 客户端登录 用户名+密码
@!CLIENT LOGIN_EX 用户名+会话号
@!CLIENT SU 权限提升

@!CLIENT PROXY 客户端换新的目标

*/
#include "myClient.h"
#include <string>

typedef int(*mycmd_proc)(CxMyClient* cli, const char* buf, int size);

struct sx_cmd_t
{
	const char* cmd;
	mycmd_proc proc;
	int state;
	int privilege;
	std::string help;
};

int mycmd_client_list(CxMyClient* cli, const char* buf, int size);

/**
让客户端连接到另外一个服务上
*/
int mycmd_client_proxy(CxMyClient* cli, const char* buf, int size);

int mycmd_system_helo(CxMyClient* cli, const char* buf, int size);
int mycmd_system_help(CxMyClient* cli, const char* buf, int size);

extern struct sx_cmd_t mycmds[];
extern unsigned int mycmds_count;

#endif // myCmd_h__
