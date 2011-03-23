#!/bin/sh

echo -e "Content-type: text/html\n\n"
echo "<html>"
cat ../../../header.html
cat << EOF
  <title>Test for semi-automatism.</title>
</head>
EOF
cat ../../../body.html
cat << EOF

<big><big><center>Test for semi-automatism.</center></big></big>
<p>
EOF

input=`echo $QUERY_STRING | \
        cut -f 2 -d '=' | \
        sed 's/%3E/>/g' | \
        sed 's/%0D%0A//g'`

echo "The substitution:<br>"
echo $input | sed 's//<br>/g'
echo $input | ./sequence | sed 's/$/<br>/'

cat ../../../footer.html
cat << EOF
</body>
</html>
EOF
