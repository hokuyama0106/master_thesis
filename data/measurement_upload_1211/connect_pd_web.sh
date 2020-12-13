#./bin/bash
curl "https://itkpd-test.unicorncollege.cz/componentTypes?project=P" -o /dev/null -w "%{time_total}\n" 2> /dev/null -s
