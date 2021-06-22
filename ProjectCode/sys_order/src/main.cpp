#include "db.hpp"
#include "httplib.h"

#define WWWROOT "./wwwroot"
using namespace httplib;

order_sys::TableDish* tb_dish = NULL;
order_sys::TableOrder* tb_order = NULL;

void DishInsert(const Request& req, Response& rsp)
{
	//1. 业务处理
	//1.1 解析正文(json反序列化)，得到菜品信息
	Json::Value dish;
	Json::Reader reader;
	//json反序列化，表示将body数据反序列化后保存到dish中
	bool ret = reader.parse(req.body, dish);
	if (ret == false)
	{
		Json::Value reason;
		Json::FastWriter writer;
		reason["result"] = false;
		reason["reason"] = "dish info parse failed!";
		rsp.status = 400;
		rsp.body = writer.write(reason);
		rsp.set_header("Content-Type", "application/json");
		std::cout << "insert dish parse error" << std::endl;
		return ;
	}
	//1.2 将菜品信息插入到数据库
	ret = tb_dish->Insert(dish);	
	if (ret == false)
	{
		Json::Value reason;
		Json::FastWriter writer;
		reason["result"] = false;
		reason["reason"] = "mysql insert failed!";
		rsp.status = 500;
		rsp.body = writer.write(reason);
		rsp.set_header("Content-Type", "application/json");
		std::cout << "mysql insert dish error" << std::endl;
		return ;
	}
	//2.设置响应信息，状态码默认为200
	//rsp.status = 200;
	return ;
}
void DishDelete(const Request& req, Response& rsp)
{
	//1、获取要删除的菜品id   /dish/id
	int dish_id = std::stoi(req.matches[1]);
	//2、数据库的删除操作
	bool ret = tb_dish->Delete(dish_id);
	if (ret == false)
	{
		std::cout << "mysql delete dish error" << std::endl;
		rsp.status = 500;
		return ;
	}
	return ;
}
void DishUpdate(const Request& req, Response& rsp)
{
	int dish_id = std::stoi(req.matches[1]);	
	Json::Value dish;
	Json::Reader reader;
	bool ret = reader.parse(req.body, dish);
	if (ret == false)
	{
		rsp.status = 400;
		std::cout << "update dish parse info failed!" << std::endl;
		return ;
	}
	dish["id"] = dish_id;
	ret = tb_dish->Update(dish);
	if (ret == false)
	{
		std::cout << "mysql update dish error" << std::endl;
	}
	return ;
}

void DishGetAll(const Request& req, Response& rsp)
{
	Json::Value dishes;
	bool ret = tb_dish->SelectAll(&dishes);
	if (ret == false)
	{
		std::cout << "mysql selectAll dish error" << std::endl;
		rsp.status = 500;
		return ;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(dishes);
	rsp.set_header("Content-Type", "application/json");
	return ;
}
void DishGetOne(const Request& req, Response& rsp)
{
	int dish_id = std::stoi(req.matches[1]);	
	Json::Value dish;
	bool ret = tb_dish->SelectOne(dish_id, &dish);
	if (ret == false)
	{
		std::cout << "mysql selectOne dish error" << std::endl;
		rsp.status = 500;
		return;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(dish);
	return ;
}

void OrderInsert(const Request& req, Response& rsp)
{
	Json::Value order;
	Json::Reader reader;
	bool ret = reader.parse(req.body, order);
	if (ret == false)
	{
		std::cout << "insert parse order error" << std::endl;
		rsp.status = 400;
		return;
	}
	ret = tb_order->Insert(order);
	if (ret == false)
	{
		std::cout << "mysql insert order error" << std::endl;
		rsp.status = 500;
		return;
	}
	return ;
}
void OrderDelete(const Request& req, Response& rsp)
{
	int order_id = std::stoi(req.matches[1]);
	bool ret = tb_order->Delete(order_id);
	if (ret == false)
	{
		std::cout << "mysql delete order error" << std::endl;
		rsp.status = 500;
		return;
	}
	return ;
}
void OrderUpdate(const Request& req, Response& rsp)
{
	int order_id = std::stoi(req.matches[1]);
	Json::Value order;
	Json::Reader reader;
	bool ret = reader.parse(req.body, order);
	if (ret == false)
	{
		std::cout << "update parse order error" << std::endl;
		rsp.status = 400;
		return;
	}
	order["id"] = order_id;
	ret = tb_order->Update(order);
	if (ret == false)
	{
		std::cout << "mysql update order error" << std::endl;
		rsp.status = 500;
		return;
	}
	return ;
}

void OrderGetAll(const Request& req, Response& rsp)
{
	Json::Value orders;
	bool ret = tb_order->SelectAll(&orders);
	if (ret == false)
	{
		std::cout << "mysql selectAll order error" << std::endl;
		rsp.status = 500;
		return;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(orders);
	return ;
}
void OrderGetOne(const Request& req, Response& rsp)
{
	int order_id = std::stoi(req.matches[1]);
	Json::Value order;
	bool ret = tb_order->SelectOne(order_id, &order);
	if (ret == false)
	{
		std::cout << "mysql selectOne order error" << std::endl;
		rsp.status = 500;
		return;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(order);
	
	return ;
}

int main()
{
	tb_dish = new order_sys::TableDish();
	tb_order = new order_sys::TableOrder();

	Server srv;
	srv.set_base_dir(WWWROOT);
	//正则表达式：(\d+) 表示匹配一个数字字符一次或多次
	//正则表达式：() 表示捕捉匹配括号中规则的文本
	//R"()" 表示括号中的字符串去除了特殊字符的特殊含义
	srv.Post("/dish", DishInsert);
	srv.Delete(R"(/dish/(\d+))", DishDelete);
	srv.Put(R"(/dish/(\d+))", DishUpdate);
	srv.Get("/dish", DishGetAll);
	srv.Get(R"(/dish/(\d+))", DishGetOne);

	srv.Post("/order", OrderInsert);
	srv.Delete(R"(/order/(\d+))", OrderDelete);
	srv.Put(R"(/order/(\d+))", OrderUpdate);
	srv.Get("/order", OrderGetAll);
	srv.Get(R"(/order/(\d+))", OrderGetOne);

	srv.listen("0.0.0.0", 8080);
	return 0;
}
