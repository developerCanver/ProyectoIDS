<?php

namespace Database\Seeders;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Hash;


class DatabaseSeeder extends Seeder
{
    /**
     * Seed the application's database.
     *
     * @return void
     */
    public function run()
    {
        // \App\Models\User::factory(10)->create();

        DB::table('users')->insert([
            'name' => 'Admin',
            'email' => 'canverlanix@gmail.com',
            'password' => Hash::make('12345678'),
        ]);

        DB::table('btns')->insert([
                   
            'sistema'   =>  '',
            'libreria'  =>  'disabled',
            'paquetes'  =>  'disabled',
            'daq'   =>  'disabled',
            'snort' =>  'disabled',
            'red'   =>  'disabled',
            'prequisitos'   =>  'disabled',
        
        ]);
    }
}
