<?php

namespace App\Providers;

use Illuminate\Support\ServiceProvider;
use Validator;
class AppServiceProvider extends ServiceProvider
{
    /**
     * Register any application services.
     *
     * @return void
     */
    public function register()
    {
        //
    }

    /**
     * Bootstrap any application services.
     *
     * @return void
     */
    public function boot()
    {
        Validator::extend('mayus', function ($attribute, $value, $parameters, $validator) {
            return preg_match('/[A-Z]/',$value);
        });

        Validator::extend('caracter', function ($attribute, $value, $parameters, $validator) {
            return preg_match('/[@$!%*#?&]/',$value);
        });

       
    }
}
