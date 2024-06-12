// 引入所需模块
const express = require('express');
const bodyParser = require('body-parser');
const path = require('path');

// 创建Express应用
const app = express();

// 设置静态文件目录
app.use(express.static(path.join(__dirname, 'public')));

// 使用body-parser中间件解析POST请求体
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// 路由：获取动物信息
app.get('/api/animals/:id', (req, res) => {
    const animalId = req.params.id;
    // 在这里查询数据库或其他数据源获取动物信息
    const animal = {
        id: animalId,
        name: "熊猫",
        category: "哺乳动物",
        description: "熊猫（学名：Ailuropoda melanoleuca）是中国特有的一种大熊科动物。",
        image: "panda.jpg"
    };
    res.json(animal);
});

// 启动服务器
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log('Server is running on port ${PORT}');
});
