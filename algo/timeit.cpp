#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
    // freopen("input","r",stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#endif

#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif