html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=gb2312">
    <title>COM</title>
    <style type="text/css">
    body
    {
        text-align:left;
        padding-left:30px;
    }
    table
    {
        margin:20px auto auto auto;
    }
    tr.style1
    {
        border:1px;
        background-color:#000040;
        color:#FFFFFF;
        text-align:center;
        height:20px;
    }
    tr.style2
    {
        border:0;
        background-color:#B9B9FF;
        color:black;
        text-align:center;
        height:20px;
    }
    input{
        width:95px;
        text-align:center;
    }
    .header
    {
        color:#FFFFFF;
      border-left:1px solid #FD6F03;
      border-right:1px solid #FD6F03;
        border-top:1px solid #FD6F03;
        text-align:left;
        background-color:#000040;
        font-weight:bold;
        height:24px;
        padding-left:5px;
    }
    .class1
    {
        text-align:left;
        font-size:12px;
        padding-left:5px;
        padding-top:5px;
        border-left:1px solid #FD6F03;
        border-right:1px solid #FD6F03;
        background-color:#DFDFDF;
    }
    .class2
    {
        border-left:0px solid #FD6F03;
        border-right:0px solid #FD6F03;
        border-bottom:0px solid #FD6F03;
        text-align:center;
        background-color:#B9B9FF;
        height:30px;
    }
    .class2 table
    {
         margin:10px auto 20 auto;
    }

    .tdclass
    {
        font-size:10px;
        width:100px;
        text-align:center;
    }
    fieldset {
        padding:10px;
        margin:10px;
        width:900px;
        color:#333;
        border:#06c dashed 1px;
    }
    legend {
        color:#FFFFFF;
        font-weight:800;
        background:#4A90E6;
    }
    </style>
    <script>
    var count=0;
    function addRow(){
        var newTr = wgTb.insertRow();
        var cur_rows = wgTb.rows.length;
        if(newTr != null)
        {
            newTr.setAttribute("className","style2");
            newTr.setAttribute("class","style2");
            var newTd0 = newTr.insertCell();
            var newTd1 = newTr.insertCell();
            var newTd2 = newTr.insertCell();
            var newTd3 = newTr.insertCell();
            var newTd4 = newTr.insertCell();
            var newTd5 = newTr.insertCell();
            var newTd6 = newTr.insertCell();
            var newTd7 = newTr.insertCell();
            var newTd8 = newTr.insertCell();

            count = cur_rows - 1;
            newTd0.innerHTML = cur_rows - 1;
            newTd1.innerHTML ='<input id="serialNo'+count+'" type="text" name="AC_SerialNo'+count+'" value="" />';
            newTd2.innerHTML ='<input id="ip'+count+'" type="text" name="AC_ip'+count+'"  value="" />';
            newTd3.innerHTML ='<input id="port'+count+'" type="text" name="AC_port'+count+'"  value="" />';
            newTd4.innerHTML ='<input id="gate1_'+count+'" type="text" name="gate1_name'+count+'"  value="1号门" />';
            newTd5.innerHTML ='<input id="gate2_'+count+'" type="text" name="gate2_name'+count+'"  value="2号门" />';
            newTd6.innerHTML ='<input id="gate3_'+count+'" type="text" name="gate3_name'+count+'"  value="3号门" />';
            newTd7.innerHTML ='<input id="gate4_'+count+'" type="text" name="gate4_name'+count+'"  value="4号门" />';
            newTd8.innerHTML ='<input type="button" name="deleGate" value="删除" onclick="del(this)" />';

            count++;
        }

    }


    function del(o)
    {
        var t = document.getElementById('wgTb');
        var rowCount = t.rows.length;
        if(rowCount == 2){
            alert("至少配置1个门禁主机控制器");
            return ;
        }
        else{
            var index = o.parentNode.parentNode.rowIndex;
            t.deleteRow(index);
            var i;
            var nextid;
            for(i=index;i<t.rows.length;i++)
            {

                t.rows[i].cells[0].innerHTML = i.toString();

                nextid = i + 1;
                var val1 = document.getElementById("serialNo"+nextid).value;
                var val2 = document.getElementById("ip"+nextid).value;
                var val3 = document.getElementById("port"+nextid).value;
                var val4 = document.getElementById("gate1_"+nextid).value;
                var val5 = document.getElementById("gate2_"+nextid).value;
                var val6 = document.getElementById("gate3_"+nextid).value;
                var val7 = document.getElementById("gate4_"+nextid).value;

                t.rows[i].cells[1].innerHTML = '<input id="serialNo'+i+'" type="text" name="AC_SerialNo'+i+'" value="'+val1+'" />';
                t.rows[i].cells[2].innerHTML = '<input id="ip'+i+'" type="text" name="AC_ip'+i+'" value="'+val2+'" />';
                t.rows[i].cells[3].innerHTML = '<input id="port'+i+'" type="text" name="AC_port'+i+'" value="'+val3+'" />';
                t.rows[i].cells[4].innerHTML = '<input id="gate1_'+i+'" type="text" name="gate1_name'+i+'" value="'+val4+'" />';
                t.rows[i].cells[5].innerHTML = '<input id="gate2_'+i+'" type="text" name="gate2_name'+i+'" value="'+val5+'" />';
                t.rows[i].cells[6].innerHTML = '<input id="gate3_'+i+'" type="text" name="gate3_name'+i+'" value="'+val6+'" />';
                t.rows[i].cells[7].innerHTML = '<input id="gate4_'+i+'" type="text" name="gate4_name'+i+'" value="'+val7+'" />';
            }
        }
    }
    </script>
</head>

<body bgcolor="#4A90E6" >
    <fieldset>
        <legend>门禁配置</legend>
        <FORM name="command" action="/goform/wgand_config" method="post">
            <table id="wgTb" width="900px">
                <%AspGetAccessControlerInfo();%>
            </table>
            <p></p>
            <input type="button" name="addGate" value="手动增加" onclick="addRow()" style="height:22;width:80"/>
            <input type="submit" name="saveGate" value="保存修改" style="height:22;width:80"/>
        </FORM>
    </fieldset>
</body>

</html>
