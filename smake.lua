local spinner = import('smake/enhancedSpinner')
local gpp = import('smake/gpp')

spinner.SetOptions({ symbols = 'clock' })

function smake.build()
    gpp():makeGlobal()

    flags('-O3', '-c')
    standard('c++20')
    include('include')
    inputr('src')

    spinner.Call(compile, 'Building', '✅ Built')

    runIn('build', 'ar rvs libhcss.a *.o')
    run('rm ./*.o')
end