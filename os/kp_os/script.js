// переменные для обращения к элементам DOM-страницы
const vmp_var = document.getElementById('virtualMemoryPage');
const result_button = document.querySelector('.res_b');
const clear_button = document.querySelector('.clr_b');

//функция перевода строки двоичного кода в красивый вид по байтам
function formatBinary(binaryString) {
  return binaryString.match(/.{1,4}/g).join(' ');
}

//событие нажатия кнопки Рассчитать
result_button.addEventListener('click', function() {
  //вывод шестнадцатеричного номера виртуальной страницы
  let parentDiv = document.getElementById('vp_hex');
  let childSpan = document.createElement('p');
  let hex = vmp_var.value.toString(16).padStart(8, '0');
  //console.log(hex);
  childSpan.textContent = hex;
  childSpan.classList.add('text', 'add');
  parentDiv.appendChild(childSpan);

  //вывод двоичного номера виртуальной страницы
  parentDiv = document.getElementById('vp_bin');
  childSpan = document.createElement('p');
  let bin = parseInt(hex, 16).toString(2).padStart(32, '0');
  let binFormated = formatBinary(bin);
  //console.log(binFormated);
  childSpan.textContent = binFormated;
  childSpan.classList.add('text', 'add');
  parentDiv.appendChild(childSpan);

  //вычисление составляющих вартуального адреса страницы
  let vpn1 = binFormated.slice(0, 12);
  let vpn1_hex = parseInt(bin.slice(0, 10), 2).toString(16).toUpperCase();
  let vpn2 = binFormated.slice(12, 24);
  let vpn2_hex = parseInt(bin.slice(10, 20), 2).toString(16).toUpperCase();
  let po = binFormated.slice(25);
  let po_hex = parseInt(bin.slice(20), 2).toString(16).toUpperCase();
  let fp_fn = parseInt(bin.slice(0, 10), 2) + parseInt(bin.slice(10, 20), 2);
  console.log('vpn1 = ' + vpn1 + ' или ' + parseInt(bin.slice(0, 10), 2));
  console.log('vpn2 = ' + vpn2 + ' или ' + parseInt(bin.slice(10, 20), 2));
  console.log('po = ' + po);
  console.log('fp_fn = ' + fp_fn);

  //вывод индекса в таблице страниц верхнего уровня
  parentDiv = document.getElementById('id_ul');
  childSpan = document.createElement('p');
  childSpan.textContent = vpn1 + ' или ' + vpn1_hex;
  childSpan.classList.add('text', 'add');
  parentDiv.appendChild(childSpan);

  //вывод индекса в таблице страниц нижнего уровня
  parentDiv = document.getElementById('id_ll');
  childSpan = document.createElement('p');
  childSpan.textContent = vpn2 + ' или ' + vpn2_hex;
  childSpan.classList.add('text', 'add');
  parentDiv.appendChild(childSpan);

  //вывод смещения на странице
  parentDiv = document.getElementById('smesh');
  childSpan = document.createElement('p');
  childSpan.textContent = po + ' или ' + po_hex;
  childSpan.classList.add('text', 'add');
  parentDiv.appendChild(childSpan);

  //вычисление номера физической страницы
  parentDiv = document.getElementById('fp');
  childSpan = document.createElement('p');
  let fp = (fp_fn * 4096) + parseInt(bin.slice(20), 2);
  childSpan.textContent = '(' + fp_fn.toString(16).toUpperCase() + ' * 4096) + ' + po_hex + ' = ' + fp.toString(16).toUpperCase();
  childSpan.classList.add('text', 'add');
  parentDiv.appendChild(childSpan);

  //переключение доступности кнопок
  clear_button.disabled = false;
  result_button.disabled = true;
})

//событие нажатия кнопки Очистить
clear_button.addEventListener('click', function() {
  //удаление прошлых расчётов
  document.querySelectorAll('.add').forEach(element => element.remove());

  //переключение доступности кнопок
  clear_button.disabled = true;
  result_button.disabled = false;

  //очистка поля ввода
  vmp_var.value = '';
})
