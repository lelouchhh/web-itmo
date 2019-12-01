function button_func(){
  let div = document.getElementById("text");
  let rows = document.getElementById("rows").value;
  let cols = document.getElementById("cols").value;
  table_create(rows, cols);
  remove(div);
  func1 = document.getElementById("size");
  func2 = document.getElementById("insert_head");
  func3 = document.getElementById("delete_col");
  func4 = document.getElementById("magic");
  func5 = document.getElementById("delete_tables");
  func1.style.visibility = 'visible';      
  func2.style.visibility = 'visible';
  func3.style.visibility = 'visible';
  func4.style.visibility = 'visible';
  func5.style.visibility = 'visible'; 

}
function remove(block) {
  return block.style.visibility= 'hidden';
}

function table_create(rows, cols){
  let tbl = document.createElement("table");
  let counter = 0;
  let col_counter = 0;
  for(let i=0;i<rows;i++)
  {
    let tr = tbl.insertRow();
    for(let j=0;j<cols;j++)
    {
      counter++;
      let td = tr.insertCell();
      textarea = td.appendChild(document.createElement("textarea"));
      button =  td.appendChild(document.createElement("button"));
      table_edit(textarea, button, counter);
      td.id = "td" + counter;
    } 
  let place = document.getElementById("table")
  col_counter++;
  place = document.getElementsByTagName("table")[0];
  place = place.appendChild(tr);
  place.id= "tr" + col_counter;
  }
  }
function table_edit(textarea, button, counter){
  let text = "CLICK HERE";
  button.innerHTML = text;
  textarea.setAttribute("id", "lot_of_textarea" + counter);
  button.setAttribute("id","buttons" + counter);
  button.setAttribute("onclick", "delete_row(this.id, lot_of_textarea" + counter + ".id)");
  let value = textarea.getAttribute("value");
  return textarea, button;
}

function delete_row(id_b, id_t){
  let textarea = document.getElementById(id_t).value;
  let crash_t = document.getElementById(id_t);
  let crash_b = document.getElementById(id_b);
  let p = document.createElement("p");
  let t = document.createTextNode(textarea);
  p.appendChild(t);

  return crash_b.parentNode.replaceChild(p, crash_b), crash_t.parentNode.replaceChild(p, crash_t);
}
function size_edit(id){
  let size = document.getElementById("input_size").value;
  let choice = document.getElementById("select").options.selectedIndex;
  let value_choice = document.getElementById("select").options[choice].value;
  tables = document.getElementById("tables");
  tables.style.width = size + "px";
  tables.style.border = value_choice;
  let button = document.getElementById("size_button");
  return button.innerHTML  = size + " px " + value_choice;
}
function insert_head(){
  let insert_text = document.getElementById("insert_text").value;
  let caption = document.getElementById("tables").createCaption();
  caption.innerHTML = insert_text;
}
function delete_col(){
  let delete_input = document.getElementById("delete_input").value;
  let tr = document.getElementById("tr" + delete_input);
  if(tr != undefined){
    return tr.parentNode.removeChild(tr);
  }
  else{alert("WRONG!")}
}
function magic(){
  let x = document.getElementById("tables").rows[0].cells.length;
  let y = document.getElementById("tables").rows.length;
  count = x*y;
  let random_row = randomInteger(1, count);
  let random_color = randomInteger(1, 5);
  let row = document.getElementById("td" + random_row);
  let colors = ["red", "yellow", "black", "green", "blue"]
  let random_color_text = randomInteger(1,5);
  row.style.backgroundColor = colors[random_color];
  let texts = ["serif", "sans-serif", "monospace", "cursive", "system-ui"];
  let random_text = randomInteger(1,5);
  row.style.fontFamily = texts[random_text];
  p_row = row.getElementsByTagName("p")[0];
  p_row.style.color = colors[random_color_text];
  let random_size = randomInteger(15,25);
  row.style.fontSize = random_size + "pt";
}

function randomInteger(min, max) { 
  let rand = min - 0.5 + Math.random() * (max - min + 1);
  return Math.round(rand);
}

function delete_tables(){
  tables = document.getElementById("tables");
  tables.parentNode.removeChild(tables);
  func1 = document.getElementById("size");
  func2 = document.getElementById("insert_head");
  func3 = document.getElementById("delete_col");
  func4 = document.getElementById("magic");
  func5 = document.getElementById("delete_tables");
  func1.style.visibility = 'hidden';      
  func2.style.visibility = 'hidden';
  func3.style.visibility = 'hidden';
  func4.style.visibility = 'hidden';
  func5.style.visibility = 'hidden'; 
  func6 = document.getElementById("text");
  func6.style.visibility = 'visible'
  new_table = document.createElement("table");
  new_table.id = "tables";
  place = document.getElementById("table");
  place.appendChild(new_table);
}
