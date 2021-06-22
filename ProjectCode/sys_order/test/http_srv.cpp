#include "httplib.h"

void hello(const httplib::Request& req, httplib::Response& rsp)
{
	std::cout << req.method << std::endl;	
	std::cout << req.path << std::endl;	
	std::cout << req.body << std::endl;	
	auto it = req.headers.begin();
	for (; it != req.headers.end(); ++it)
	{
		std::cout << it->first << " = " << it->second << std::endl;
	}
	it = req.params.begin();
	for (; it != req.params.end(); ++it)
	{
		std::cout << it->first << " = " << it->second << std::endl;
	}

	rsp.status = 200;
	rsp.body = "<html><body><h1>Hello WhiteShirtI</h1></body></heml>";
	rsp.set_header("Content-Type", "text/html");

	return ;
}

int main()
{
	httplib::Server srv;
	//get请求方法
	srv.Get("/hello", hello);
	srv.set_base_dir("./wwwroot");
	srv.listen("0.0.0.0", 8080);
	return 0;
}
