const addButton = document.getElementById('addButton');
const fioInput = document.getElementById('fio');
const startStationSelect = document.getElementById('startStation');
const endStationSelect = document.getElementById('endStation');
const messageDiv = document.getElementById('message');

//Заполняем select'ы
const stations = ['Санкт-Петербург', 'Москва', 'Тверь', 'Тосно', 'Псков'];
stations.forEach(station => {
  let option = document.createElement('option');
  option.value = station;
  option.text = station;
  startStationSelect.add(option);
  option = document.createElement('option');
  option.value = station;
  option.text = station;
  endStationSelect.add(option);
});

addButton.addEventListener('click', addData);

async function addData() {
  const fio = fioInput.value;
  const startStation = startStationSelect.value;
  const endStation = endStationSelect.value;

  if (!fio || !startStation || !endStation) {
    messageDiv.textContent = 'Заполните все поля!';
    messageDiv.style.color = 'red';
    return;
  }

  try {
    const response = await fetch('http://127.0.0.1:3000/add-data', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ fio, startStation, endStation }),
    });

    if (!response.ok) {
      const errorData = await response.json();
      messageDiv.textContent = errorData.error || 'Ошибка при добавлении данных';
      messageDiv.style.color = 'red';
      return;
    }

    messageDiv.textContent = 'Данные успешно добавлены!';
    messageDiv.style.color = 'green';
    fioInput.value = '';
    startStationSelect.value = '';
    endStationSelect.value = '';
  } catch (error) {
    console.error('Ошибка:', error);
    messageDiv.textContent = 'Произошла неизвестная ошибка';
    messageDiv.style.color = 'red';
  }
}
