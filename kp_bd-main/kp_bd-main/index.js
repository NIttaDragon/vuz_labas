const express = require('express')
const {Pool} = require ('pg')
const app = express()
const port = 8080
const ejs = require('ejs');
const bodyParser = require('body-parser');

//доступ к базе данных
const pool = new Pool({
    user: 'postgres',
    host: 'localhost',
    database: 'postgres',
    password: '2567',
    port: 5432,
});


app.set('view engine', 'ejs');
app.set('views','./templates');
app.use(express.static('public'));

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
    extended: true
}))

app.listen(port, ()=>{
    console.log('server on '+port);
});



//create main page
app.get('/', (req, res)=>{
    res.render('page'); //передача данных в html
})

//create cars page
let car_str;
pool.query('Select * from cars', (err, res)=>{
    if(err) throw err;
    car_str = res.rows;
})

app.get('/cars', (req, res)=>{
    res.render('cars', {data: car_str}); //передача данных в html
})

//create car_insert page
app.get('/cars/insert', (req, res)=>{
    res.render('car_insert', {data: car_str}); //передача данных в html
})
app.post('/cars/insert', (req,res)=>{
    const input_car_id = req.body.input_car_id;
    const input_campacity = req.body.input_campacity;
    const input_fk_worker_id = req.body.input_fk_worker_id;
    const input_fk_fabric_id = req.body.input_fk_fabric_id;
    const input_fk_shop_id = req.body.input_fk_shop_id;
    pool.query(`Insert into "cars" ("car_id", "campacity", "fk_worker_id", "fk_fabric_id", "fk_shop_id")
                values($1, $2, $3, $4, $5)`, [input_car_id, input_campacity, input_fk_worker_id, input_fk_fabric_id, input_fk_shop_id]);
})

//create car_delete page
app.get('/cars/delete', (req, res)=>{
    res.render('car_delete', {data: car_str}); //передача данных в html
})
app.post('/cars/delete', (req,res)=>{
    const output_car_id = req.body.output_car_id;
    pool.query(`delete from "cars"
                where "car_id"=$1`, [output_car_id]);
})

//create fabric page
let fabric_str;
pool.query('Select * from fabric', (err, res)=>{
    if(err) throw err;
    fabric_str = res.rows;
})

app.get('/fabric', (req, res)=>{
    res.render('fabric', {data: fabric_str}); //передача данных в html
})

//create fabric_insert page
app.get('/fabric/insert', (req, res)=>{
    res.render('fabric_insert', {data: fabric_str}); //передача данных в html
})
app.post('/fabric/insert', (req,res)=>{
    const input_fabric_id = req.body.input_fabric_id;
    const input_country = req.body.input_country;
    const input_town = req.body.input_town;
    const input_fabric_name = req.body.input_fabric_name;
    pool.query(`Insert into "fabric" ("fabric_id", "country", "town", "fabric_name")
                values($1, $2, $3, $4)`, [input_fabric_id, input_country, input_town, input_fabric_name]);
})

//create fabric_delete page
app.get('/fabric/delete', (req, res)=>{
    res.render('fabric_delete', {data: fabric_str}); //передача данных в html
})
app.post('/fabric/delete', (req,res)=>{
    const output_fabric_id = req.body.output_fabric_id;
    pool.query(`delete from "fabric"
                where "fabric_id"=$1`, [output_fabric_id]);
})

//create products page
let products_str;
pool.query('Select * from products', (err, res)=>{
    if(err) throw err;
    products_str = res.rows;
})

app.get('/products', (req, res)=>{
    res.render('products', {data: products_str}); //передача данных в html
})

//create products_insert page
app.get('/products/insert', (req, res)=>{
    res.render('products_insert', {data: products_str}); //передача данных в html
})
app.post('/products/insert', (req,res)=>{
    const input_product_id = req.body.input_product_id;
    const input_price = req.body.input_price;
    const input_fk_fabric_id = req.body.input_fk_fabric_id;
    pool.query(`Insert into "products" ("product_id", "price", "fk_fabric_id")
                values($1, $2, $3)`, [input_product_id, input_price, input_fk_fabric_id]);
})

//create products_delete page
app.get('/products/delete', (req, res)=>{
    res.render('products_delete', {data: products_str}); //передача данных в html
})
app.post('/products/delete', (req,res)=>{
    const output_product_id = req.body.output_product_id;
    pool.query(`delete from "products"
                where "product_id"=$1`, [output_product_id]);
})

//create shop page
let shop_str;
pool.query('Select * from shop', (err, res)=>{
    if(err) throw err;
    shop_str = res.rows;
})

app.get('/shop', (req, res)=>{
    res.render('shop', {data: shop_str}); //передача данных в html
})

//create shop_insert page
app.get('/shop/insert', (req, res)=>{
    res.render('shop_insert', {data: shop_str}); //передача данных в html
})
app.post('/shop/insert', (req,res)=>{
    const input_shop_id = req.body.input_shop_id;
    const input_adress = req.body.input_adress;
    const input_phone = req.body.input_phone;
    const input_director = req.body.input_director;
    const input_worker = req.body.input_worker;
    pool.query(`Insert into "shop" ("shop_id", "adress", "phone", "director", "worker")
                values($1, $2, $3, $4, $5)`, [input_shop_id, input_adress, input_phone, input_director, input_worker]);
})

//create shop_delete page
app.get('/shop/delete', (req, res)=>{
    res.render('shop_delete', {data: shop_str}); //передача данных в html
})
app.post('/shop/delete', (req,res)=>{
    const output_shop_id = req.body.output_shop_id;
    pool.query(`delete from "shop"
                where "shop_id"=$1`, [output_shop_id]);
})

//create workers page
let workers_str;
pool.query('Select * from workers', (err, res)=>{
    if(err) throw err;
    workers_str = res.rows;
})

app.get('/workers', (req, res)=>{
    res.render('workers', {data: workers_str}); //передача данных в html
})

//create workers_insert page
app.get('/workers/insert', (req, res)=>{
    res.render('workers_insert', {data: workers_str}); //передача данных в html
})
app.post('/workers/insert', (req,res)=>{
    const input_worker_id = req.body.input_worker_id;
    const input_first_name = req.body.input_first_name;
    const input_last_name = req.body.input_last_name;
    const input_sex = req.body.input_sex;
    const input_birth = req.body.input_birth;
    const input_work_date = req.body.input_work_date;
    pool.query(`Insert into "workers" ("worker_id", "first_name", "last_name", "sex", "birth", "work_date")
                values($1, $2, $3, $4, $5, $6)`, [input_worker_id, input_first_name, input_last_name, input_sex, input_birth, input_work_date]);
})

//create workers_delete page
app.get('/workers/delete', (req, res)=>{
    res.render('workers_delete', {data: workers_str}); //передача данных в html
})
app.post('/workers/delete', (req,res)=>{
    const output_worker_id = req.body.output_worker_id;
    pool.query(`delete from "workers"
                where "worker_id"=$1`, [output_worker_id]);
})

//create product_shop
let product_shop_str;
pool.query('Select * from product_shop', (err, res)=>{
    if(err) throw err;
    product_shop_str = res.rows;
})

app.get('/product_shop', (req, res)=>{
    res.render('product_shop', {data: product_shop_str}); //передача данных в html
})

//create product_shop_insert page
app.get('/product_shop/insert', (req, res)=>{
    res.render('product_shop_insert', {data: product_shop_str}); //передача данных в html
})
app.post('/product_shop/insert', (req,res)=>{
    const input_fk_product_id = req.body.input_fk_product_id;
    const input_fk_shop_id = req.body.input_fk_shop_id;
    const input_existing = req.body.input_existing;
    pool.query(`Insert into "product_shop" ("fk_product_id", "fk_shop_id", "existing")
                values($1, $2, $3)`, [input_fk_product_id, input_fk_shop_id, input_existing]);
})

//create product_shop_delete page
app.get('/product_shop/delete', (req, res)=>{
    res.render('product_shop_delete', {data: product_shop_str}); //передача данных в html
})
app.post('/product_shop/delete', (req,res)=>{
    const output_fk_product_id = req.body.output_fk_product_id;
    const output_fk_shop_id = req.body.output_fk_shop_id;
    pool.query(`delete from "product_shop"
                where "fk_product_id"=$1 and "fk_shop_id"=$2`, [output_fk_product_id, output_fk_shop_id]);
})