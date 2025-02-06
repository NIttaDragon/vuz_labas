const express = require('express');
const { Pool } = require('pg');
const cron = require('node-cron');
const cors = require('cors'); //Для CORS

const app = express();
app.use(express.json());
app.use(cors()); // Разрешаем CORS (важно для разных доменов!)


// Настройки подключения к базе данных
const pool = new Pool({
  user: 'postgres',
  host: 'localhost',
  database: 'postgres',
  password: '2567',
  port: 5432,
  max: 10,
  idleTimeoutMillis: 30000,
});

// Маршрут для добавления данных
app.post('/add-data', async (req, res) => {
  try {
    const { fio, startStation, endStation } = req.body;
    const client = await pool.connect();
    try {
      await client.query(
        'INSERT INTO mails VALUES (0, $1, $2, $3, 0, $2, 0)',
        [fio, startStation, endStation]
      );
      res.json({ message: 'Данные успешно добавлены' });
    } catch (error) {
      console.error('Ошибка при добавлении данных:', error);
      res.status(500).json({ error: 'Ошибка при добавлении данных' });
    } finally {
      client.release();
    }
  } catch (error) {
    console.error('Ошибка:', error);
    res.status(500).json({ error: 'Ошибка сервера' });
  }
});


// Функция обновления данных в базе данных (вызывается из cron)
cron.schedule('*/2 * * * *', async () => { // Каждую минуту
  try {
    await updateData();
  } catch (error) {
    console.error("Ошибка в cron задаче обновления данных:", error);
  }
});

async function updateData() {
  const client = await pool.connect();
  try {
    await client.query('UPDATE mails SET status = 1 WHERE status = 0 and st_o = st_t'); //Пример обновления.  Измените по необходимости
    console.log('Данные обновлены.');
  } catch (error) {
    console.error('Ошибка при обновлении данных:', error);
  } finally {
    client.release();
  }
}

// Запуск сервера
app.listen(3000, () => console.log('Сервер запущен на порту 3000'));
