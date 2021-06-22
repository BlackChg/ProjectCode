**html**：完成页面的布局

**css**：样式语言--对标签容器进行样式修饰，让简单的html页面更加好看

**js**：JavaScript脚本语言，让页面动态渲染展示  

​          

# html基础知识   

html 标签是整个 html 文件的根标签(最顶层标签) 

head 标签中写页面的属性. 

body 标签中写的是页面上显示的内容 

title 标签中写的是页面的标题.

标题标签: h1-h6 有六个, 从 h1 - h6. 数字越大, 则字体越小

```
<html> 
    <head> 
        <title>第一个页面</title>
    </head> 
    <body>
    <h1>WhiteShirtI</h1>
    <h2>WhiteShirtI</h2>
    </body> 
</html>
```



把一段比较长的文本粘贴到 html 中, 会发现并没有分成段落. 在html中使用` <p>` 标签括起一个段落进行换行。当然也可以在段落内使用`<br/>`标签进行换行操作。

加粗: strong 标签 和 b 标签 

倾斜: em 标签 和 i 标签 

删除线: del 标签 和 s 标签 

下划线: ins 标签 和 u 标签

```
<p>段落，
在html中一般的回车并不起作用，会被解释成为一个空格<br/>但是br不一样，br标签的作用就是换行。
</p>
<p><b>比如b标签就是加粗</b></p>
<p><i>比如i标签就是斜体</i></p>
<p><s>比如s标签就是删除线</s></p>
<p><u>比如u就是下划线</u></p>
```



**img 标签**

必须带有 src 属性. 表示图片的路径.

alt: 替换文本. 当文本不能正确显示的时候, 会显示一个替换的文字. 

title: 提示文本. 鼠标放到图片上, 就会有提示. 

width/height: 控制宽度高度. 高度和宽度一般改一个就行, 另外一个会等比例缩放. 否则就会图片失衡. 

border: 边框, 参数是宽度的像素. 但是一般使用 CSS 来设定

```
<img src="./rose.jpg" alt="显示失败时的信息" title="图片提示信息" width="150px" height="150px" border="5px">
```



**超链接标签: a**
href: 必须具备, 表示点击后会跳转到哪个页面.
target: 打开方式. 默认是 _self. 如果是 _blank 则用新的标签页打开  

点击项并非一定是文本形式，也可以时图片或者其他信息都可以

```
<a href="http://www.baidu.com" target="_blank">点击这里打开新标签访问百度</a>
```



**表格标签**
table 标签: 表示整个表格
tr: 表示表格的一行
td: 表示一个单元格/列
th: 表示表头单元格. 会居中加粗
thead: 表格的头部区域(注意和 th 区分, 范围是比 th 要大的)
tbody: 表格得到主体区域.  

```
<table align="center" border="1" cellpadding="1" cellspacing="0" width="200" height="20">
<tr>
    <th>菜名</th>
    <th>单价</th>
    <th>折扣</th>
</tr>
<tr>
    <td align="center">红烧茄子</td>
    <td align="center">￥18</td>
    <td align="center">8.8折</td>
</tr>
<tr>
    <!--colspan合并列， rowspan合并行-->
    //合并3列，并靠右显示
    <td colspan="3" align="right">总价：￥18</td>
</tr>
</table>
```



**列表标签**
主要使用来布局的. 整齐好看.
无序列表[重要] ul li , .
有序列表[用的不多] ol li
自定义列表[重要] dl (总标签) dt (小标题) dd (围绕标题来说明) 上面有个小标题, 下面有几个围绕着标题来展开
的  

```
<ul>
    <li>ul/li是无序列表</li>
    <li>ul/li是无序列表</li>
</ul>

<ol>
    <li>ol/li是有序列表</li>
    <li>ol/li是有序列表</li>
</ol>
        
<dl>
    <dt>dl/dt是小标题</dt>
    <dd>dl/dd是围绕标题的描述</dd>
    <dd>dl/dd是围绕标题的描述</dd>
</dl>
```



**表单标签**
表单是让用户输入信息的重要途径.
分成两个部分:
表单域: 包含表单元素的区域. 重点是 form 标签.
表单控件: 输入框 , 提交按钮等. 重点是 input 标签  

```
<from action="/dish" method="post">
    <input type="text" placeholder="input标签默认是文本框"> <br/>
    <input type="password" placeholder="type属性为password是密码框"> <br/>
    <input type="radio" name="sex">type属性为radio是单选框,name属性相同则默认为同一组-男 <br/>
    <input type="radio" name="sex" checked="checked">type属性为radio是单选框-女<br/>
    <input type="checkbox"> checkbox是复选框-吃饭 <br/>
    <input type="checkbox"> checkbox是复选框-睡觉 <br/>
    <input type="checkbox"> checkbox是复选框-打游戏<br/>
    <input type="checkbox" id="testid">
    <label for="testid">label标签for属性与对应的输入框id对应起来，这时候点击文字也能选中</label><br/>
    <input type="button" value="button是普通按钮" onclick="alert('alert是提示框调用函数')"><br/>
    <input type="submit" value="submit是提交按钮">点击这里就会向服务器提交表单域中的表单数据<br/>
    <input type="file" value="file是文件选择按钮框"><br/>
    <input type="reset" value="reset是清空按钮，会清空表单域的所有数据"><br>
</from>
```



**下拉菜单标签**
下拉菜单
option 中定义 selected="selected" 表示默认选中  

```
<select>
    <option selected="selected">--请选择年份--</option>
    <option>1990</option>
    <option>1991</option>
    <option>1992</option>
</select>
```



**无语义标签**: div & span
div 标签, division 的缩写, 含义是 分割
span 标签, 含义是跨度
就是两个盒子. 用于网页布局
div 是独占一行的, 是一个大盒子.
span 不独占一行, 是一个小盒子  

```
<div>div是个大盒子独占一行</div>
<span>span是个小盒子并不独占一行</span>
<span>span是个小盒子并不独占一行</span>
```



**多媒体标签**
video标签：视频 audio标签：音频  

```
<video src="https://www.runoob.com/try/demo_source/movie.mp4" controls="controls" type="video/mp4">video是视频控件标签</video>
<audio src="https://www.runoob.com/try/demo_source/horse.mp3" controls="controls" type="audio/mp3">audio是音频控件标签</audio>
```



# css基础知识

选择器 + {一条/N条声明}
选择器决定针对谁修改 (找谁)
声明决定修改啥. (干啥)
声明的属性是键值对. 使用 ; 区分键值对, 使用 : 区分键和值  

引入css的两种方式：

1. 当前html页面的style标签中加入
2. 通过`<link rel='dns-prefetch' href='[//s.w.org](https://s.w.org/)' />`

```
<style>
    p {//修饰所有p标签
        /* 设置字体颜色 */
        color: red;
        /* 设置字体大小 */
        font-size: 30px;
    }
</style>
<p>hello</p>
```



**选择器**

- 标签选择器：通过标签名来修饰
- 类选择器 ：通过.类名来修饰
- id 选择器 ：通过#id来修饰
- 通配符选择器 ：通过*来修饰

```
<style>
    .a {
        color: red;
        font-size: 30px;
    }
    #123{
     	color: red;
        font-size: 30px;
    }
    *{
     	color: red;
        font-size: 30px;
    }
</style>
<p class="a">hello</p>
<div id="123">hello</div>
```



# vue.js

通常将vue放到文件末尾

```
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
```



js代码都写在`<script></script>`中

页面可以根据后台修改数据而进行动态渲染

1. 创建了一个 div, id 为 app
2. 在 div 中使用 "插值表达式" {{message}} 来指定 div 内部的内容.
3. js 中创建了一个名为 app 的 Vue 实例. 构造函数中的参数是一个对象.
4. 参数中的 el 字段是一个选择器, 对应到 html 中的具体元素id.
5. 参数中的 data 字段是一个特定的对象, 用来放置数据.
6. data 中的 message 属性值, 就对应到 {{message}} 中的内容. 
7. Vue 会自动解析 {{message}} , 并把 data 中对应的名字为 message 的属性值替换进去  

{{ }} 中还可以放入一个表达式 

```
<div id="app">{{message}}</div>
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
<script>
var app = new Vue({
	el: '#app',
	data: {
	message: 'hello',
    },
});
</script>
```

{{ }} 中还可以放入一个表达式  

**v-cloak**  

HTML 解析代码的时候是从上往下解析. 如果加载 Vue 的速度比较慢, 那么就会在界面上看到 {{ }} 这样的内容.  

```
<style>
        [v-cloak] {
            display: none;
        }
</style>

<div id="app" v-cloak> {{message}} </div>
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
<script>
    // 2s 之后再创建 Vue 实例
    setTimeout(function () {
        let app = new Vue({
            el: '#app',
            data: {
            	message: 'hello',
            }
        });
    }, 2000);
</script>
```



**v-bind**  

使用 v-bind 进行动态绑定属性  

```
<div id="app" v-cloak>
            <a v-bind:href="url">点击这里打开新标签访问百度</a>
</div>
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
<script>
var app = new Vue({
	el: '#app',
	data: {
		message: 'hello',
		url:"https://www.baidu.com"
    },
});
</script>
```



函数

```
	<div id="app">
            <div>result: {{getresult()}}</div>
        </div>
        <script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
        <script>
            app = new Vue({
                el: '#app',
                //存放数据属性
                data: {
                    message: 'hello',
                    url:"https://www.baidu.com",
                    num1:10,
                    num2:20
                },
                //行为函数methods
                methods:{
                    getresult:function(){
                        console.log("whiteshirti");
                        return this.num1+this.num2;
                    }
                }
            });
	</script>
```



**v-on** 
v-on 后面使用 : 连接后续的事件名称  

```
	<div id="app">
            <div><button v-on:click="myclick(`你好`)">提交按钮</button></div>
            <div><a href="http://www.baidu.com" v-on:click="myclick(`即将转到百度`)">点击这里打开新标签访问百度</a>	</div>
        </div>
        <script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
        
        <script>
            app = new Vue({
                el: '#app',
                data: {
                    message: 'hello',
                    url:"https://www.baidu.com",
                    num1:10,
                    num2:20
                },
                methods:{
                    myclick:function(event){
                        alert(event);
                    }
                }
            });
        </script>
```

v-on:click.prevent 

表示阻止后续事件

```
//点击之后就不会跳到百度
<div><a href="https://www.baidu.com" v-on:click.prevent="myclick(`即将转到百度`)">点击这里打开新标签访问百度</a></div>
```



**v-if v-else**

```
		<div id="app">
            <div>
                <h1 v-if="chinese==false">{{message}}</h1>
                <h1 v-else>{{message1}}</h1>
            </div>
        </div>
        <script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
        
        <script>
            app = new Vue({
                el: '#app',
                data: {
                    chinese: false,
                    message: 'hello',
                    message1: '你好',
                    url:"https://www.baidu.com",
                    num1:10,
                    num2:20
                },
                methods:{
                    myclick:function(event){
                        alert(event);
                    }
                }
            });
```



**v-for**

```
		<div id="app">
            <div>
                <h1 v-for="score in scores">{{score}}</h1>
            </div>
        </div>
        <script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
        
        <script>
            app = new Vue({
                el: '#app',
                data: {
                    chinese: false,
                    message: 'hello',
                    message1: '你好',
                    url:"https://www.baidu.com",
                    num1:10,
                    num2:20,
                    scores:[88,77,99]
                },
                methods:{
                    myclick:function(event){
                        alert(event);
                    }
                }
            });
        </script>
```

