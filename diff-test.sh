echo "First run..."

/home/work/memdb/pintools/analysis-tools/cache-waste-analysis -e -p /home/work/llvm_log_server > run1 &

sleep 1

./actonization-test-1

echo "Finished first run"

echo "Second run..."

/home/work/memdb/pintools/analysis-tools/cache-waste-analysis -e -p /home/work/llvm_log_server > run2 &

sleep 1

./actonization-test-1

echo "Finished second run"

DIFF=$(diff run1 run2) 
echo "----------------------"
if [ "$DIFF" != "" ] 
    then
        echo "FAIL: Inconsistent cache usage."
else
    echo "PASS: Consisten cache usage."
fi
echo "----------------------"
